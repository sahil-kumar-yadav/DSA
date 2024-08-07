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

Node *findMiddle(Node *head){
    Node *slow = head;
    Node* fast = head;

    if(!head) return NULL;
    
    while(fast != NULL){
        fast = fast->next;
        
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    return slow;
}

Node* reverseLL(Node* head){

    cout<<"head "<<head->data<<endl;
    if(!head) return NULL;
    if(!head->next) return head;
    Node *prev = NULL;
    Node *curr = head;
    Node *Next = curr->next;

    while(Next != NULL){
        cout<<"prev "<<(prev ? prev->data : -1) <<" ";
        cout<<"curr "<<curr->data<<" ";
        cout<<"next "<<Next->data<<" "<<endl;
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }
   
    cout<<"prev "<<prev->data<<endl;

    return prev;

} 

bool checkPalindrome(Node *head)
{

    Node *middle = findMiddle(head);
    cout<<"mid "<<middle->data<<endl;

    middle->next = reverseLL(middle->next);
    cout<<"printing "<<endl;
    printLL(head);

    Node *ptr1 = head;
    Node *ptr2 = middle->next;

    while(ptr2 != NULL){
        if(ptr1->data != ptr2->data){
            cout<<" Not palindrome loop"<<endl;
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    // cout<<ptr1->data<<" "<<middle->data<<endl;
    if(ptr2 == NULL && ptr1->data != middle->data ) return false;

    return true;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(1);
    // Node *fifth = new Node(5);
    // Node *sixth = new Node(6);
    // Node *seventh = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    // fourth->next = fifth;
    // fifth->next = sixth;
    // sixth->next = seventh;

    bool check = checkPalindrome(head);

    if (check)
    {
        cout << "LL is Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindrome " << endl;
    }

    return 0;
}