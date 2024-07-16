#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;

    }
};

Node* buildTree(){
    int data;
    cout<<"Enter data for node ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter data for "<<data<< "left ";
    root->left = buildTree();

    cout<<"Enter data for "<<data<< "right ";
    root->right = buildTree();

    return root;
}
int main(){
    Node *root = buildTree();
    return 0;

}