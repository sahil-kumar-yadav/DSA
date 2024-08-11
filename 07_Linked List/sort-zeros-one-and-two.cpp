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

void sortZerosAndOnces(Node *&head)
{
    if (!head)
        return;

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *temp = head;

    while (temp)
    {
        if (temp->data == 0)
        {
            // zero vale my append karna hai
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            // one my append karna hai
            oneTail->next = temp;
            oneTail = temp;
        }
        else
        {
            // two my
            twoTail->next = temp;
            twoTail = temp;
        }

        temp = temp->next;
    }
    // remove -1 from all head

    Node *temp0 = zeroHead;
    zeroHead = zeroHead->next;
    temp0->next = NULL;
    delete temp0;

    Node *temp1 = oneHead;
    cout<<"one head "<<oneHead->data<<endl;
    oneHead = oneHead->next;
    cout<<"one head "<<oneHead->data<<endl;
    cout<<"temp  "<<temp1->data<<endl;
    temp1->next = NULL;
    cout<<"temp next "<<endl;
    delete temp1;
    
    Node *temp2 = twoHead;
    twoHead = twoHead->next;
    temp2->next = NULL;
    delete temp2;

   
   
    oneTail->next = twoHead;
    twoTail->next = NULL;
    
    if(zeroHead){
        zeroTail->next = oneHead;
        head = zeroHead;
    }
    else if(!zeroHead && oneHead){
        head = oneHead;
    }
    else if(!zeroHead && !oneHead){
        head = twoHead;
    }

}

int main()
{
    // 2 2 1 2 1

    Node *head = new Node(2);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->next = new Node(1);
    printLL(head);
    sortZerosAndOnces(head);
    printLL(head);

    return 0;
}