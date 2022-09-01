#include <iostream>
#define GARBAGE -6969
using namespace std;

class Queue
{
    int *arr;
    int size, front = -1, back = -1;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[size];
    }

    bool isEmpty()
    {
        return front == back;
    }

    bool isFull()
    {
        return back == size - 1;
    }

    void enqueue(int e)
    {
        arr[++back] = e;
    }

    int dequeue()
    {
        return arr[++front];
    }

    void display()
    {
        for (int i = front + 1; i <= back; i++)
            cout << arr[i] << endl;
    }
};

class Stack
{
    Queue *primary; // its front always points to top of stack
    Queue *secondary;
    int size;

public:
    Stack(int s)
    {
        size = s;
        primary = new Queue(size * 100);
        secondary = new Queue(size * 100);
    }

    void push(int e) // costly 
    // 1. empty primary to secondary
    // 2. enqueue e to primary
    // 3. empty secondary to primary
    {
        if (primary->isFull())
        {
            cout << "OVERFLOW" << endl;
            return;
        }

        while (!primary->isEmpty())
            secondary->enqueue(primary->dequeue());
        primary->enqueue(e);
        while (!secondary->isEmpty())
            primary->enqueue(secondary->dequeue());
    }

    int pop()
    {
        if (primary->isEmpty())
        {
            cout << "UNDERFLOW" << endl;
            return GARBAGE;
        }
        return primary->dequeue();
    }

    void display() { primary->display(); }
    bool isEmpty() { return primary->isEmpty(); }
    bool isFull() { return primary->isFull(); }
};

int main()
{
    Stack s(5);
    s.push(12);
    s.push(14);
    s.push(16);
    s.display();
    cout << "POPED: " << s.pop() << endl;
    s.display();
    return 0;
}