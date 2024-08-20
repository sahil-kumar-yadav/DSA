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

Node* lowestCommonAncester(Node *root ,Node *p,Node *q){
    if(!root){
        return NULL;
    }

    // check karo

    if(root->data == q->data){
        return q;
    }
    if(root->data == p->data){
        return p;
    }

    Node *leftans = lowestCommonAncester(root->left,p,q);
    Node *rightans = lowestCommonAncester(root->right,p,q);

    if(leftans == NULL && rightans == NULL){
        // q,p sirf left my ho
        return NULL;
    }
    else if(leftans != NULL && rightans == NULL){
        return leftans;
    }
    else if(leftans != NULL && rightans == NULL){
         //q,p sirf right my ho
        return rightans;
    }
    else{
        // root he ans hai
        // q,p left or right dono my ho skta hai
        return root;
    }

}

int main(){
    // 10 20 40 -1 -1 50 60 -1 -1 70 -1 -1 30 -1 -1
    Node *root = buildTree();
    cout<<"Printing the Inorder of tree"<<endl;
    InOrderTraversal(root);
    Node *p = new Node(60);
    Node *q = new Node(40);
    Node *LCA = lowestCommonAncester(root,p,q);
    cout<<endl;
    cout<<"Lowest common ancester "<<LCA->data<<endl;

    return 0;

}