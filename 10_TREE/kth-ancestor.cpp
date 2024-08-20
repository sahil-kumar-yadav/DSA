#include<iostream>

using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(){
        this->data = 0;
        this->left = 0;
        this->left = 0;
    }
    Node(int x){
        this->data = x;
        this->left = 0;
        this->left = 0;
    }
};


Node* buildTree(){
    // cout<<"Enter data ";
    int data;
    cin>>data;
    if(data == -1) return NULL;

    Node *root = new Node(data);

    // cout<<data<<" left ";
    root->left = buildTree();
    // cout<<data<<" right ";
    root->right = buildTree();

    return root;

}

void InOrderTraversal(Node *root){
    if(!root)
        return ;

    // CLR
    InOrderTraversal(root->left);
    cout<<root->data<<" ";
    InOrderTraversal(root->right);
}

bool kthAncester(Node *root ,int &k,Node *p){
    if(!root){
        return NULL;
    }

    // check karo

    if(root->data == p->data){
        return true;
    }

    bool leftans = kthAncester(root->left,k,p);
    bool rightans = kthAncester(root->right,k,p);

    // vaps aate time check karo kahi ans to nahi milla

    if(leftans || rightans){
        k--;
    }

    if(k == 0){
        // yahi hai root node
        cout<<endl;
        cout<<"answer "<<root->data;
        k = -1;
    }
    
    return (leftans || rightans);

}

int main(){
    // 10 20 40 70 -1 -1 -1 90 80 110 -1 -1 120 -1 -1 -1 30 -1 60 90 -1 -1 100 -1 -1 
    Node *root = buildTree();
    cout<<"Printing the Inorder of tree"<<endl;
    InOrderTraversal(root);
    int k = 2;
    Node *p = new Node(120);
    bool kth = kthAncester(root,k,p);
    cout<<endl;
    cout<<"kth ancester present "<<kth<<endl;

    return 0;

}