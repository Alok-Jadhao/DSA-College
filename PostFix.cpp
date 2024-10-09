#include <iostream>

using namespace std;

class Stack
{
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    int peek()
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

    int pop()
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

int post_eval(string s)
{
    Stack stack;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (isdigit(s[i]))
        {
            stack.push(int(s[i] - '0'));
        }
        else
        {
            int operand2 = stack.pop();
            int operand1 = stack.pop();

            switch (s[i])
            {
            case '+':
                stack.push(operand1 + operand2);
                break;
            case '-':
                stack.push(operand1 - operand2);
                break;
            case '*':
                stack.push(operand1 * operand2);
                break;
            case '/':
                stack.push(operand1 / operand2);
                break;
            default:
                printf("Error: Invalid Operator\n");
                break;
            }
        }
    }

    return stack.peek();
}

int main()
{
    string s;
    cin >> s;
    cout << post_eval(s) << endl;
}
