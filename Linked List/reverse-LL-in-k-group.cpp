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
    cout<<endl;
}

int findLength(Node *root)
{

    Node *temp = root;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }

    return len;
}

Node *reverseInK(Node *head, int k)
{
    if (head == NULL)
    {
        cout<<"Linked List is empty"<<endl;
        return NULL;
    }
    int len = findLength(head);

    if (k > len)
    {
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;
    Node *Next = curr->next;

    
    
    // Step A : reverse k
    int count = 0;
    while (count<k)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        count++;
    }

    // step B : recursive call
    if (Next != NULL)
    {
        head->next = reverseInK(Next, k);
    }

    return prev;

    //
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    printLL(head);
    int k = 5;
    head = reverseInK(head, k);
    cout<<"reversed "<<endl;
    printLL(head);

    return 0;
}