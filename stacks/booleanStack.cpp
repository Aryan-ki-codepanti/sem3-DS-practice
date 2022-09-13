#include <iostream>
using namespace std;

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

bool isOperator(char c)
{
    return (c == '&' || c == '|' || c == '!');
}

bool checkPrecedence(char a, char b)
{
    if (a == '!' && isOperator(b))
        return true;
    else if (a == '&' && (b == '&' || b == '|'))
        return true;
    else if (a == '|' && b == '|')
        return true;
    return false;
}

string infixToPostfix(string infix)
{
    int n = infix.length();
    Stack<char> operator_stack(n);
    string postfix = "";

    for (int i = 0; i < n; i++)
    {
        if (!isOperator(infix[i]))
            postfix += infix[i];
        else
        {
            while (!operator_stack.isEmpty() && checkPrecedence(operator_stack.peek(), infix[i]))
                postfix += operator_stack.pop();
            operator_stack.push(infix[i]);
        }
    }
    while (!operator_stack.isEmpty())
        postfix += operator_stack.pop();

    return postfix;
}

bool eval(bool first, bool second, char op)
{
    switch (op)
    {
    case '!':
        return !first;
    case '&':
        return first && second;
    case '|':
        return first || second;
    default:
        return 0;
    }
}

bool convertToBool(char c)
{
    switch (c)
    {
    case 'T':
    case 't':
        return true;
    case 'F':
    case 'f':
        return false;
    default:
        return false;
    }
}

bool evaluatePostfix(string postfix)
{

    int n = postfix.length();
    Stack<bool> operand_stack(n);

    int first, second;
    for (int i = 0; i < n; i++)
    {
        // operand
        if (!isOperator(postfix[i]))
            operand_stack.push(convertToBool(postfix[i])); // convert to ints

        else
        {
            if (postfix[i] == '!')
            {
                second = false; // any value
                first = operand_stack.pop();
            }
            else
            {
                second = operand_stack.pop();
                first = operand_stack.pop();
            }

            operand_stack.push(eval(first, second, postfix[i])); // push the result of first op second
        }
    }

    return operand_stack.pop();
}

int main()
{
    string s;
    cout << "Enter infix" << endl;
    cin >> s;
    cout << "Postfix : " << infixToPostfix(s) << endl;
    cout << "Value: " << evaluatePostfix(infixToPostfix(s)) << endl;
    return 0;
}