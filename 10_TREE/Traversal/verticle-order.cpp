#include <iostream>
#include <map>

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

void verticleTraversal(Node *root, int d, multimap<int, int> &mp)
{
    if (!root)
        return;

    // entry karo
    mp.insert({d, root->data});

    // left jao
    verticleTraversal(root->left, d - 1, mp);

    // right jao
    verticleTraversal(root->right, d + 1, mp);
}

int main()
{
    // 3 9 -1 -1 20 15 -1 -1 7 -1 -1
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    multimap<int, int> mp;
    verticleTraversal(root, 0, mp);
    cout << "Printing map " << endl;
    for (auto it : mp)
    {
        cout << it.first << " -> ";
        cout << it.second << endl;
    }
    return 0;
}