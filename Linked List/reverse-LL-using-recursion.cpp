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

void reverseLLRecursion(Node *prev, Node *curr, Node *&head)
{
    if (curr == NULL)
        return;

    Node *Next = curr->next;

    if (Next)
    {
        // ek kaam kudh kardo baki recurion
        curr->next = prev;
        prev = curr;
        curr = next;
        curr->next = reverseLLRecursion(prev, Next);
    }

    
    
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    printLL(head);
    Node *prev = NULL;
    Node *curr = head;
    reverseLLRecursion(prev, curr, head);
    printLL(head);

    return 0;
}