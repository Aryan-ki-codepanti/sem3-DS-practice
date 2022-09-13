
template <typename T>
class Stack
{
    int top = -1, size;
    T *arr;

public:
    Stack(int a)
    {
        size = a;
        arr = new T[a];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(T element)
    {
        arr[++top] = element;
    }

    T pop()
    {
        return arr[top--];
    }

    T peek()
    {
        return arr[top];
    }
};
