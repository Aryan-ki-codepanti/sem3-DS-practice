#include <iostream>
#define GARBAGE -6969
using namespace std;

class Stack
{
    int *arr;
    int size, top = -1;

public:
    Stack(int s)
    {
        size = s;
        arr = new int[s];
    }

    bool isFull()
    {
        return top == size - 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int e)
    {
        arr[++top] = e;
    }

    int pop()
    {
        return arr[top--];
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

class Queue
{
    Stack *primary;
    Stack *secondary;
    int size;

public:
    Queue(int s)
    {
        size = s;
        primary = new Stack(s);
        secondary = new Stack(s);
    }

    bool isFull() { return primary->isFull(); }
    bool isEmpty() { return primary->isEmpty(); }

    void enqueue(int a)
    {
        if (primary->isFull())
        {
            cout << "Primary overflow" << endl;
            return;
        }
        primary->push(a);
    }

    int dequeue()
    {
        if (primary->isEmpty())
            return GARBAGE;

        while (!primary->isEmpty())
            secondary->push(primary->pop());

        int temp = secondary->pop();

        while (!secondary->isEmpty())
            primary->push(secondary->pop());

        return temp;
    }

    void display() { primary->display(); }
};

int main()
{

    Queue q(5);

    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(5);
    q.display();
    cout << "Dequeued: " << q.dequeue() << endl;
    q.display();

    q.enqueue(6);
    q.display();

    return 0;
}