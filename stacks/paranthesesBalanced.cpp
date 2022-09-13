#include <iostream>
#include "Stack.h"

using namespace std;

bool isOpening(char ch)
{
    return (ch == '{' || ch == '[' || ch == '(');
}
bool isClosing(char ch)
{
    return (ch == '}' || ch == ']' || ch == ')');
}

bool isMatching(char left, char right)
{
    if (left == '{' && right == '}')
        return true;
    else if (left == '[' && right == ']')
        return true;
    else if (left == '(' && right == ')')
        return true;
    return false;
}

bool isValidExpression(string exp)
{
    char ch;
    int n = exp.length();
    Stack<char> stack_open_parens(n);

    for (int i = 0; i < n; i++)
    {
        ch = exp[i];

        if (isOpening(ch))
            stack_open_parens.push(ch);
        else if (isClosing(ch))
        {
            if (stack_open_parens.isEmpty())
                return false;
            else if (!isMatching(stack_open_parens.pop(), ch))
                return false;
        }
    }
    return stack_open_parens.isEmpty();
}

int main()
{
    string s;
    cout << "Enter expression" << endl;
    cin >> s;
    cout << "Validity : " << isValidExpression(s) << endl;
    return 0;
}