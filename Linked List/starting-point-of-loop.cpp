#include <iostream>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

void printLL(Node *root)
{

    Node *temp = root;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void findStartingPoint(Node *head)
{
    if (!head)
        return;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL)
    {
        cout<<"slow "<<slow->data<<" fast "<<fast->data<<endl;
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (slow == fast)
        {
            slow = head;
            break; // meet kar gye
        }
    }
    cout << "head is " << head->data << endl;
    cout << "meet point is " << fast->data << endl;
    // abh slow ko head sy start karo
    // jabh slow or fast meet karge vahi starting point hoga
    slow = head;
    Node *prev = fast;
    while (slow != fast)
    {
        prev = fast;
        fast = fast->next;
        slow = slow->next;
    }

    cout << "prev  point is " << prev->data << endl;
    cout << "starting point is " << fast->data << endl;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = head;

    findStartingPoint(head);

    return 0;
}