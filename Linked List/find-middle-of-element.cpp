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


Node* Findmiddle(Node *head){
    Node* slow = head; // 1X speed
    Node* fast = head; // 2X speed
    while(fast != NULL){
        cout<<"slow "<<slow->data<<" fast "<<fast->data<<endl;
        fast = fast->next;
        // check if fast can move next step
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;

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

    Node *middle = Findmiddle(head);
    cout<<"middle element is "<<middle->data<<endl;

    return 0;
}