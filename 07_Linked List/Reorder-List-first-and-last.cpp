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

Node *reverseLL(Node *&head)
{
    if (!head)
        return NULL;

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
    curr->next = prev;
    head = curr;
    return head;
}

Node *copyLL(Node *head)
{
    if (!head)
        return NULL;

    Node *newHead = new Node(-1);
    Node *temp = newHead;

    while (head)
    {
        Node *newNode = new Node(head->data);
        temp->next = newNode;
        temp = newNode;
        head = head->next;
    }

    Node *minus = newHead;
    newHead = newHead->next;
    minus->next = NULL;
    delete minus;

    return newHead;
}

Node *reOrder(Node *head1, Node *head2)
{
    if (head2 == NULL)
    {
        return NULL;
    }

    Node *newHead = new Node(-1);
    Node *temp = newHead;
    cout << "printing head1 " << endl;
    printLL(head1);
    cout << "printing head2 " << endl;
    printLL(head2);
    while ((head1->data != head2->data) && (head1 != NULL || head2 != NULL))
    {

        cout << "h1 " << head1->data << " ";
        cout << " h2 " << head2->data << endl;
        temp->next = head1;
        temp = head1;

        if (head1->next)
            head1 = head1->next;

        temp->next = head2;
        temp = head2;

        if (head2->next)
            head2 = head2->next;

        if (head2->next)
        {
            if (head1->next->data == head2->data)
            {
                temp->next = head1;
                temp = head1;
                temp->next = head2;
                temp = head2;
                temp->next = NULL;
                return newHead->next;
            }
        }
        else{
            break;
        }
    }
    
    
    temp->next = head1;
    temp = head1;
    temp->next = NULL;

    return newHead->next;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    // head->next->next = new Node(3);
    // head->next->next->next = new Node(4);
    // head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);
    // head->next->next->next->next->next->next = new Node(7);
    Node *head2 = copyLL(head);
    head2 = reverseLL(head2);
    printLL(head);
    printLL(head2);

    Node *reOrdered = reOrder(head, head2);
    cout << "printing reOrdered" << endl;
    printLL(reOrdered);

    return 0;
}