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
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    first->next = second;
    second->next = third;

    printLL(first);

    return 0;

}