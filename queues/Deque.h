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

// PS : no boundary cases

template <typename T>
class Deque
{
    int size, front = -1, back = -1;
    T *arr;

public:
    Deque(int a)
    {
        size = a;
        arr = new T[a];
    }

    bool isFull()
    {
        return circular_increment(back, size) == front;
    }

    bool isEmpty()
    {
        return front == -1 && back == -1;
    }

    void first_enqueue(T n)
    {
        front = 0;
        back = 0;
        arr[front] = n;
    }

    T last_dequeue()
    {
        T x = arr[front];
        front = -1;
        back = -1;
        return x;
    }

    void enqueue_back(T n)
    {

        if (isEmpty()) // 1st element to enter
        {
            first_enqueue(n);
            return;
        }
        back = circular_increment(back, size);
        arr[back] = n;
    }

    void enqueue_front(T n)
    {
        if (isEmpty())
        {
            first_enqueue(n);
            return;
        }

        front = circular_decrement(front, size);
        arr[front] = n;
    }

    T dequeue_front()
    {

        if (front == back)
            return last_dequeue();

        T x = arr[front];
        front = circular_increment(front, size);
        return x;
    }

    T dequeue_back()
    {
        if (front == back)
            return last_dequeue();

        T x = arr[back];
        back = circular_decrement(back, size);
        return x;
    }
};
