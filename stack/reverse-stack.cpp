#include <iostream>
#include <stack>

using namespace std;

void printStack(stack<int> s)
{

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

void insertAtBottom(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertAtBottom(s, target);
    s.push(topElement);
}

void reverseStack(stack<int> &s)
{

    // base case
    if (s.empty())
    {
        return;
    }
    int top = s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s, top);
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "original " << endl;
    printStack(s);

    reverseStack(s);
    cout << "reversed stack" << endl;
    printStack(s);

    return 0;
}