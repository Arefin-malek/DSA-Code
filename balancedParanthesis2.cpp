#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
    int top;

public:
    int a[MAX];
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "Stack Overflow";
        return false;
    }
    else
    {
        a[++top] = x;
        // cout << x << " pushed into stack\n";
        return true;
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow";
        return 0;
    }
    else
    {
        int x = a[top--];
        return x;
    }
}
int Stack::peek()
{
    if (top < 0)
    {
        cout << "Stack is Empty";
        return 0;
    }
    else
    {
        int x = a[top];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
void Matching(Stack s, string exp)
{
    for (int i = 0; i < 17; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            int a = s.peek();
            if (a == '(' && exp[i] == ')' || a == '{' && exp[i] == '}' || a == '[' && exp[i] == ']')
                s.pop();
            else
            {
                cout << endl
                     << "Parenthesis Unbalanced" << endl;
                exit(1);
            }
        }
        if (i == 16)
        {
            if (s.isEmpty())
            {
                cout << endl
                     << "Parenthesis Balanced" << endl;
            }
            else
            {
                cout << endl
                     << "Parenthesis Unbalanced" << endl;
            }
        }
    }
}

int main()
{
    class Stack s;
    int t;
    cin >> t;
    while (t--)
    {
        string si;
        cin >> si;
        Matching(s, si);
    }
    return 0;
}
