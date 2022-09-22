#include <iostream>
#include "Stack.h"
using namespace std;

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '/' || c == '*');
}

int eval(int first, int second, char op)
{
    switch (op)
    {
    case '/':
        return first / second;
    case '*':
        return first * second;
    case '+':
        return first + second;
    case '-':
        return first - second;
    default:
        return 0;
    }
}

int evaluatePrefix(string prefix)
{
    int n = prefix.length();
    Stack<int> stack(n);

    char c;
    int first, second;
    for (int i = n - 1; i >= 0; i--)
    {
        c = prefix[i];

        if (!isOperator(c))
            stack.push(c - '0');
        else
        {
            first = stack.pop();
            second = stack.pop();
            stack.push(eval(first, second, c));
        }
    }

    return stack.peek();
};

int main()
{
    string s;
    cin >> s;
    cout << evaluatePrefix(s);
    return 0;
}