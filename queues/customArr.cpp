#include <iostream>
#define GARBAGE -9999
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front = -1, back = -1;

public:
    Queue(int s)
    {
        size = s;
        arr = new int[s];
    }

    bool isFull()
    {
        return back == size - 1;
    }

    bool isEmpty()
    {
        return back == front;
    }

    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        back++;
        arr[back] = element;
    }

    int dequeue()
    {

        if (isEmpty())
            return GARBAGE;
        front++;
        return arr[front];
    }

    void display()
    {

        if (isEmpty())
        {
            cout << "Empty Queue" << endl;
            return;
        }

        cout << "Front -> ";
        for (int i = front + 1; i <= back; i++)
            cout << arr[i] << " ";
        cout << "<- Back " << endl;
    }
};

int main()
{
    int n;
    cout << "Enter max size of queue : ";
    cin >> n;

    Queue q(n);
    int element, choice;

    while (true)
    {
        cout << "---------QUEUE MENU--------" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        if (choice == 4)
        {
            cout << "Exiting program" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter the element to be enqueued : ";
            cin >> element;
            q.enqueue(element);
            break;

        case 2:
            element = q.dequeue();
            if (element == GARBAGE)
                cout << "UNDERFLOW" << endl;
            else
                cout << "DEQUEUED : " << element << endl;
            break;

        case 3:
            q.display();
            break;

        default:
            cout << "Make a valid choice" << endl;
            break;
        }
    }

    return 0;
}