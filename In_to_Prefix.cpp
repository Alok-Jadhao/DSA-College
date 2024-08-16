#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Stack
{
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

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
            cout << "Stack is empty";
            return -1;
        }
        return arr[top--];
    }

    void push(int x)
    {
        if (isFull())
        {
            cout << "Stack is full";
            return;
        }
        arr[++top] = x;
    }
};

void swap(char a, char b)
{
    char temp = a;
    a = b;
    b = temp;
}

string reverse(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; ++i)
    {
        // Swap characters at position i and (n - i - 1)
        swap(s[i], s[n - i - 1]);
    }
}

int getPriority(char C)
{
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

string prefix(string s)
{
    Stack stack;
    string output, rev;
    rev = reverse(s);

    for (int i = 0; s[i] != '\0'; i++)
    {

        if (!isdigit(s[i]))
        {
            stack.push(s[i]);
        }
        else
        {
            output = output + s[i];
        }

        // if (isdigit(s[i]))
        // {
        //     stack.push(int(s[i] - '0'));
        // }
        // else
        // {
        //     int operand2 = stack.pop();
        //     int operand1 = stack.pop();

        //     switch (s[i])
        //     {
        //     case '+':
        //         stack.push(operand1 + operand2);
        //         break;
        //     case '-':
        //         stack.push(operand1 - operand2);
        //         break;
        //     case '*':
        //         stack.push(operand1 * operand2);
        //         break;
        //     case '/':
        //         stack.push(operand1 / operand2);
        //         break;
        //     default:
        //         printf("Error: Invalid Operator\n");
        //         break;
        //     }
        // }
    }
}

int main()
{
    string s;
    cin >> s;
    cout << prefix(s) << endl;
}