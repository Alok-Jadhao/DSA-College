#include <iostream>
#include <algorithm>
using namespace std;

class Stack
{
    char arr[100];
    int top;

public:
    Stack() : top(-1) {}

    char peek()
    {
        return arr[top];
    }

    bool isEmpty()
    {
        return top == -1;
    }

    bool isFull()
    {
        return top == 99;
    }

    char pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        return arr[top--];
    }

    void push(char x)
    {
        if (isFull())
        {
            return;
        }
        arr[++top] = x;
    }
};

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixToPrefix(string infix)
{
    Stack s;
    string prefix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }

    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];

        if (isalpha(c))
        {
            prefix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                prefix += s.pop();
            }
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c))
            {
                prefix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty())
    {
        prefix += s.pop();
    }

    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    return 0;
}
