#include <iostream>

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

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    printLL(head);

    return 0;
}