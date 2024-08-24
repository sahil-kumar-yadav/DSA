#include <iostream>

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
    // cout << "Enter data for node " << endl;
    ;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    // cout << data << "left ";
    root->left = buildTree();

    // cout << data << "right ";
    root->right = buildTree();

    return root;
}

void ReversePreOrderTraversal(Node *root, Node *&head)
{
    if (!root)
        return;

    // RLC
    ReversePreOrderTraversal(root->right, head);
    ReversePreOrderTraversal(root->left, head);

    // yaha pe processing hogi
    root->right = head;
    root->left = NULL;
    head = root;
}
int main()
{
    Node *root = buildTree();
    // 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 7 -1 -1

    // flattern BST to LL USING Reverse Preorder i.e LRC
    Node *head = NULL;
    ReversePreOrderTraversal(root, head);

    cout << "Printing LL " << endl;
    Node *temp = root;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->right;
    }

    return 0;
}