#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int height(Node *root){
    if(!root){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight,rightHeight) + 1;
}

int main()
{
    // input 10 20 30 -1 -1 50 -1 -1 40 -1 60 70 -1 -1 80 -1 -1
    Node *root = buildTree();

    int treeheight = height(root);
    cout<<treeheight<<endl;
    return 0;
}