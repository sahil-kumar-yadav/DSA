#include <iostream>
#include <queue>
#include <vector>
// #include<algorithm>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        // this is the first node or we can say root node
        root = new Node(data);
        return root;
    }

    // not the first node

    if (root->data > data)
    {
        // insert at left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
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

int kthSmallest(Node *root, int &k)
{
    if (!root || k < 0)
    {
        return -1;
    }
    int left = kthSmallest(root->left, k);
    if (left != -1)
        return left;

    k--;

    if (k == 0)
        return root->data;

    int right = kthSmallest(root->right, k);

    return right;
}

int main()
{
    Node *root = NULL;
    // i/p : 100 50 20 70 80 129 140 160 -1
    // 3,5,1,6,2,0,8,null,null,7,4

    cout << "Enter the data for Node " << endl;
    takeInput(root);

    cout << "printing the tree " << endl;
    LevelOrder(root);
    int k = 3;
    int kthsmallest = findkth(root, k);
    cout << "lca is " << lca << endl;

    return 0;
    
}
