#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // this is the first node or we can say root node
        root = new Node(data);
        return root;
    }

    // not the first node

    if (root->data > data)
    {
        // insert at left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

int findMaximumRecursive(Node *root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }

    if(root->right){
        ans = findMaximumRecursive(root->right);
    }
    else{
        ans =  root->data;
    }

    return ans;
}

int findMinimumRecusive(Node *root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }

    if(root->left){
        ans = findMinimumRecusive(root->left);
    }
    else{
        ans =  root->data;
    }

    return ans;
}

int findMaximumItrative(Node *root){

    if(root == nullptr){
        cout<<"tree empty "<<endl;
        return -1;
    }

    // iterate to right till right exist

    Node *temp = root;
    while(temp->right){
        temp = temp->right;
    }

    
    return temp->data;
}

int findMinimumItrative(Node *root){

    if(root == nullptr){
        cout<<"tree empty "<<endl;
        return -1;
    }

    // iterate to right till right exist

    Node *temp = root;
    while(temp->left){
        temp = temp->left;
    }

    return temp->data;
}

int main()
{
     // i/p : 10 5 20 2 8 4 6 11 25 17 15 -1
    Node *root = NULL;
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    // int maxi = findMaximumRecursive(root);
    // int min = findMinimumRecusive(root);
    
    int maxi = findMaximumItrative(root);
    int min = findMinimumItrative(root);

    cout<<"maximum is "<<maxi<<endl;
    cout<<"minimum is "<<min<<endl;

    return 0;
}

