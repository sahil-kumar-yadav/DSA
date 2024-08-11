#include <iostream>
#include <stack>

using namespace std;

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

void printStack(stack<int> s)
{
    cout << endl;
    cout << "printig stack " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    int target = s.top();
    printStack(s);
    s.pop();
    cout << "target " << target << endl;
    insertAtBottom(s, target);
    printStack(s);

    return 0;
}