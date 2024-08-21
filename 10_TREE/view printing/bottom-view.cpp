#include <iostream>
#include <map>
#include <queue>

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

void BottomView(Node *root, int d, map<int, int> &mp)
{
    if (!root)
        return;

    // level order traversal karna padega
    queue<pair<Node *, int>> q;

    q.push({root, 0});

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *frontNode = temp.first;
        int hd = temp.second;
        q.pop();

        // entry hai to bhi update kardo
        mp[hd] = frontNode->data;
        if (frontNode->left)
        {
            q.push({frontNode->left, hd - 1});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right, hd + 1});
        }
    }
}

int main()
{
    // 1 2 3 -1 -1 5 6 -1 -1 -1 9 7 -1 -1 8 -1 -1 -1 -1
    // 3 6 7 9 8
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    map<int, int> mp;
    BottomView(root, 0, mp);
    cout << endl;
    cout << "Printing map " << endl;
    for (auto it : mp)
    {
        cout << it.first << " -> ";
        cout << it.second << endl;
    }
    return 0;
}