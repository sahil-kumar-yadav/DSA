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

void LeftView(Node *root, vector<int> &ans, int level)
{
    if (!root)
        return;

    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }

    LeftView(root->left, ans, level + 1);
    LeftView(root->right, ans, level + 1);
}

int main()
{
    // 10 20 30 -1 -1 40 60 -1 -1 80 -1 90 -1 -1 50 -1 70 -1 -1
    // 10 20 30 60 90
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    vector<int> ans;
    LeftView(root, ans, 0);
    cout << endl;
    cout << "Printing ans " << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}