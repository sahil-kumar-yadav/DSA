#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int x){
        this->data = x;
        this->next = NULL;
    }

};

void insertAtHead(Node* &head,int data){
    if(!head) return;

    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

void printLL(Node *root){
    
    Node *temp = root;

    while(temp)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"out"<<endl;
}

int main(){
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtHead(head,60);
    insertAtHead(head,70);
    printLL(head);


    return 0;

}