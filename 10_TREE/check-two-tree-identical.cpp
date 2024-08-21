#include <iostream>
#include <vector>

using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node()
    {
        this->data = 0;
        this->left = 0;
        this->left = 0;
    }
    Node(int x)
    {
        this->data = x;
        this->left = 0;
        this->left = 0;
    }
};

Node *buildTree()
{
    // cout<<"Enter data ";
    int data;
    cin >> data;
    if (data == -1)
        return NULL;

    Node *root = new Node(data);

    // cout<<data<<" left ";
    root->left = buildTree();
    // cout<<data<<" right ";
    root->right = buildTree();

    return root;
}

void InOrderTraversal(Node *root)
{
    if (!root)
        return;

    // CLR
    InOrderTraversal(root->left);
    cout << root->data << " ";
    InOrderTraversal(root->right);
}

bool checkIdentical(Node *p, Node *q)
{
    if (!p && !q)
        return true;

    if (p && q)
    {
        if (p->data == q->data)
        {
            bool left = checkIdentical(p->left, q->left);
            bool right = checkIdentical(p->right, q->right);
            return (left & right);
        }
        return false;
    }

    return false;
}

int main()
{
    // 10 20 130 -1 -1 40 60 -1 -1 80 -1 90 -1 -1 50 -1 70 -1 -1
    // 10 20 30 -1 -1 40 60 -1 -1 80 -1 90 -1 -1 50 -1 70 -1 -1

    Node *root1 = buildTree();
    cout << "enter for tree 2" << endl;
    Node *root2 = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root1);
    cout << endl;
    InOrderTraversal(root2);
    bool ans = checkIdentical(root1, root2);
    cout << endl;
    cout << "tree are identical " << ans << endl;

    return 0;
}