#include <iostream>
#include <queue>

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
    // cout<<"Enter data for node "<<endl;;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    // cout<<data<< "left ";
    root->left = buildTree();
    root->right = buildTree();

    // cout<<data<< "right ";

    return root;
}

void LevelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

        cout << frontNode->data << " ";
        if (frontNode->left != NULL)
        {
            q.push(frontNode->left);
        }
        if (frontNode->right != NULL)
        {
            q.push(frontNode->right);
        }
    }
}

int main()
{
    // input 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
    Node *root = buildTree();
    LevelOrder(root);
    return 0;
}