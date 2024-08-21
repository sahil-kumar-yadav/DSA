#include <iostream>
#include <map>
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

void Diagonal(Node *root, int d, map<int, vector<int>> &mp)
{
    if (!root)
        return;

    mp[d].push_back(root->data);

    Diagonal(root->left, d - 1, mp);
    Diagonal(root->right, d , mp);
}

int main()
{
    // 8 3 1 -1 -1 6 4 -1 -1 7 -1 -1 10 -1 14 13 -1 -1 -1

    Node *root = buildTree();
    InOrderTraversal(root);
    cout << endl;
    map<int, vector<int>> mp;

    Diagonal(root, 0, mp);
    cout << "Printing ans " << endl;
    for (auto it : mp)
    {
        cout << it.first << " -> ";
        for (auto ptr : it.second)
        {
            cout << ptr << " ";
        }
        cout << endl;
    }

    return 0;
}