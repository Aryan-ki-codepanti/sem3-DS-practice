
// PS here dequeue from empty queue and enqueue to full queue not handled

template <typename T>
class CircularQueue
{

    // front has idx of 1st element and back has idx of last element of queue
    int front = -1, back = -1, size;
    T *arr;

public:
    CircularQueue(int a)
    {
        size = a;
        arr = new T[a];
    }

    bool isEmpty()
    {
        return front == -1 && back == -1;
    }

    bool isFull()
    {
        int x = (back + 1) % size;
        return x == front;
    }

    void enqueue(T n)
    {
       
        if (isEmpty())
        {
            // 1st time 1st element
            front = 0;
            back = 0;
            arr[back] = n;
            return;
        }

        // other case
        back = (back + 1) % size;
        arr[back] = n;
    }

    T dequeue()
    {

        int x = arr[front];
        if (front == back) // last element to be removed
        {
            front = -1;
            back = -1;
        }
        else // other case
            front = (front + 1) % size;
        return x;
    }

};