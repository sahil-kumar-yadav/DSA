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

void removeDuplicates(Node *head)
{
    if (!head)
        return;

    Node *prev = head;
    Node *curr = head->next;

    while (curr)
    {
        if (curr->data == prev->data)
        {
            // duplicate
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            temp->next = NULL;
            delete temp;
        }
        else
        {
            curr = curr->next;
            prev = prev->next;
        }
    }
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    printLL(head);
    removeDuplicates(head);
    printLL(head);

    return 0;
}