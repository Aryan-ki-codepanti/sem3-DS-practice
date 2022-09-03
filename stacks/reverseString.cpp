#include <iostream>
#define GARBAGE -99999
using namespace std;

class Stack
{
    int size;
    int top = -1;
    int *arr;

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

    void push(int element)
    {
        if (isFull())
        {
            cout << "OVERFLOW" << endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    int pop()
    {
        if (isEmpty())
            return GARBAGE;
        int element = arr[top];
        top--;
        return element;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty Stack" << endl;
            return;
        }
        cout << arr[top] << " <--- TOP" << endl;
        for (int i = top - 1; i >= 0; i--)
            cout << arr[i] << endl;
    }
};

void reverseString(string s){
    int n = s.length();
    Stack string_stack(n);

    for (int i = 0; i < n; i++)
        string_stack.push(s[i]);

    while(!string_stack.isEmpty())
        cout << (char)string_stack.pop();
    cout << endl;
    
}

int main()
{
    string s;
    cin >> s;
    reverseString(s);
    return 0;
}