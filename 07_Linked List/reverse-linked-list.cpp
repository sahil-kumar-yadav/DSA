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

void insertAtTail(Node *&head, int data)
{
    if (!head)
        return;

    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

void printLL(Node *root)
{

    Node *temp = root;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "out" << endl;
}

void reverseLL(Node *&head)
{
    if (!head)
        return;

    Node *prev = NULL;
    Node *curr = head;
    Node *Next = head->next;

    while (Next)
    {
        curr->next = prev;
        prev = curr;
        curr = Next;
        Next = Next->next;
    }
    // cout<<"prev "<<prev->data<<" curr "<<curr->data<<" next "<<Next->data<<" "<<endl;
    curr->next = prev;
    head = curr;
    printLL(head);
}

int main()
{
    Node *head = new Node();
    int data;
    cout << "Enter data ";
    cin >> data;
    head->data = data;
    // cout << "before";
    while (data > 0)
    {
        cin >> data;
        if (data > 0)
            insertAtTail(head, data);
    }
    printLL(head);
    reverseLL(head);
    // printLL(head);

    return 0;
}