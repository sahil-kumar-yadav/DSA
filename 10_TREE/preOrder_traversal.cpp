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
    cout<<"Enter data for node "<<endl;;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<data<< "left ";
    root->left = buildTree();

    cout<<data<< "right ";
    root->right = buildTree();

    return root;
}


void preOrderTraversal(Node *root){
    if(!root)
        return ;

    // LCR
    preOrderTraversal(root->left);
    cout<<root->data<<" ";
    preOrderTraversal(root->right);
}
int main(){
    Node *root = buildTree();
    preOrderTraversal(root);
    return 0;

}