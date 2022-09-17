#include <iostream>
#define GARBAGE -6969
using namespace std;

int circular_increment(int i, int n)
{
    return (i + 1) % n;
}

int circular_decrement(int i, int n)
{
    if (i == -1 || i == 0)
        return n - 1;
    return --i;
}

class Deque
{
    int size, front = -1, back = -1;
    int *arr;

public:
    Deque(int a)
    {
        size = a;
        arr = new int[a];
    }

    bool isFull()
    {
        return circular_increment(back, size) == front;
    }

    bool isEmpty()
    {
        return front == -1 && back == -1;
    }

    void first_enqueue(int n)
    {
        front = 0;
        back = 0;
        arr[front] = n;
    }

    int last_dequeue()
    {
        int x = arr[front];
        front = -1;
        back = -1;
        return x;
    }

    void enqueue_back(int n)
    {
        if (isFull())
        {
            cout << "Can't enqueue to full queue" << endl;
            return;
        }

        if (isEmpty()) // 1st element to enter
        {
            first_enqueue(n);
            return;
        }
        back = circular_increment(back, size);
        arr[back] = n;
    }

    void enqueue_front(int n)
    {
        if (isFull())
        {
            cout << "Can't enqueue to full queue" << endl;
            return;
        }

        if (isEmpty())
        {
            first_enqueue(n);
            return;
        }

        front = circular_decrement(front, size);
        arr[front] = n;
    }

    int dequeue_front()
    {
        if (isEmpty())
        {
            cout << "Can't dequeue from empty queue" << endl;
            return GARBAGE;
        }

        if (front == back)
            return last_dequeue();

        int x = arr[front];
        front = circular_increment(front, size);
        return x;
    }

    int dequeue_back()
    {
        if (isEmpty())
        {
            cout << "Can't dequeue from empty queue" << endl;
            return GARBAGE;
        }

        if (front == back)
            return last_dequeue();

        int x = arr[back];
        back = circular_decrement(back, size);
        return x;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty queue" << endl;
            return;
        }

        if (front <= back)
        {
            cout << "Front -> ";
            for (int i = front; i <= back; i++)
                cout << arr[i] << " ";
            cout << "<- Back" << endl;
            return;
        }
        // front > back
        cout << "Front -> ";
        for (int i = front; i < size; i++)
            cout << arr[i] << " ";
        for (int i = 0; i <= back; i++)
            cout << arr[i] << " ";
        cout << "<- Back" << endl;
    }
};

int main()
{

    int n, x, choice;
    cout << "Enter max capacity of deque : " << endl;
    cin >> n;

    Deque deque(n);

    while (true)
    {
        cout << "-------DEQUE-MENU--------" << endl;
        cout << "1. Enqueue at front" << endl;
        cout << "2. Enqueue at back" << endl;
        cout << "3. Dequeue at front" << endl;
        cout << "4. Dequeue at back" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Make a choice : " << endl;
        cin >> choice;

        if (choice == 6)
        {
            cout << "Exiting program" << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter the element to be enqueued : ";
            cin >> x;
            deque.enqueue_front(x);
            break;
        case 2:
            cout << "Enter the element to be enqueued : ";
            cin >> x;
            deque.enqueue_back(x);
            break;

        case 3:
            x = deque.dequeue_front();
            cout << "Dequeued : " << x << endl;
            break;
        case 4:
            x = deque.dequeue_back();
            cout << "Dequeued : " << x << endl;
            break;

        case 5:
            deque.display();
            break;

        default:
            cout << "Make a valid choice" << endl;
            break;
        }
    }

    return 0;
}