#include <iostream>
#define GARBAGE 0

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
        for (int i = top; i >= 0; i--)
            cout << arr[i];
        cout << endl;
    }
};

void addTwoLarge(string s1, string s2)
{

    int n1 = s1.length();
    int n2 = s2.length();

    int tmp_int;
    string tmp_str;

    Stack stack1(n1);
    Stack stack2(n2);
    Stack stack_res(n1 + n2);

    // push s1 to stack 1
    for (int i = 0; i < n1; i++)
        stack1.push(s1[i] - '0');
    // push s2 to stack
    for (int i = 0; i < n2; i++)
        stack2.push(s2[i] - '0');

    // add
    int carry = 0, res;
    while (!stack1.isEmpty() || !stack2.isEmpty())
    {
        res = stack1.pop() + stack2.pop() + carry;
        carry = res / 10;
        stack_res.push(res % 10);
    }

    stack_res.display();
}

int main()
{

    // addTwoLarge("12303283433645", "83084084979799979779283");
    string s1 , s2;
    cout << "Enter two large numbers : " << endl;
    cin >> s1 >> s2;
    cout << s1  << " + " << s2 << " = ";
    addTwoLarge(s1 , s2);
    return 0;
}
