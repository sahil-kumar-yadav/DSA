#include <iostream>
#include <queue>
#include <algorithm>

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

int height(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    // tree is balanced if height of left and right is differ by one

    if (root == NULL)
    {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    return (leftAns && rightAns);
}

int main()
{
    // input 10 20 30 -1 -1 50 -1 -1 40 -1 60 70 -1 -1 80 -1 -1
    // 10 20 40 -1 -1 50 -1 -1 30 -1 -1
    Node *root = buildTree();

    bool ans = isBalanced(root);
    if (ans)
    {
        cout << "balanced" << endl;
    }
    else
    {
        cout << "Unbalanced" << endl;
    }

    

    return 0;
}