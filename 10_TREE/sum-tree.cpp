#include <iostream>
#include <vector>
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

void LevelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {

        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {

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

int convetIntoSum(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
    {
        // leaf node hai
        int temp = root->data;
        root->data = 0;
        return temp;
    }

    // CLR
    int leftData = convetIntoSum(root->left);
    // cout << root->data << " ";
    int rightData = convetIntoSum(root->right);

    int temp1 = root->data;
    root->data = leftData + rightData;
    return leftData + rightData + temp1;
}

int main()
{
    // 10 -2 8 -1 -1 -4 -1 -1 6 7 -1 -1 5 -1 -1
    // 20 -2 0 -1 -1 0 -1 -1 12 0 -1 -1 0 -1 -1
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;

    LevelOrder(root);
    cout << endl;
    int ans = convetIntoSum(root);
    LevelOrder(root);

    return 0;
}