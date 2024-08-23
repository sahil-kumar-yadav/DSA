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

void InOrder(Node *root, vector<int> &inorderArr)
{
    if (root == nullptr)
    {
        return;
    }

    InOrder(root->left, inorderArr);
    inorderArr.push_back(root->data);
    // cout<<root->data<<" ";
    InOrder(root->right, inorderArr);
}

void inOrderPreAndSucc_m1(Node *root, int node)
{
    if (!root)
        return;
    vector<int> inorderArr;

    // inoder Store karo ans my
    // Bs bhi laga skte hai
    InOrder(root, inorderArr);

    for (int i = 0; i < inorderArr.size(); i++)
    {
        if (inorderArr[i] == node)
        {
            cout << "predeccessor " << inorderArr[i - 1] << endl;
            cout << "successor " << inorderArr[i + 1] << endl;
            break;
        }
    }
}

Node *findNode(Node *root, int target)
{
    if (!root)
        return 0;

    if (root->data == target)
        return root;

    if (target > root->data)
        return findNode(root->right, target);
    else
        return findNode(root->left, target);
}

int getJustSmaller(Node *root, int target)
{
    if (!root)
        return INT_MIN;

    if (root->data > target)
    {
        return getJustSmaller(root->left, target);
    }

    int left = getJustSmaller(root->left, target);
    int right = getJustSmaller(root->right, target);
    int val = root->data == target ? INT_MIN : root->data;
    return max(val, max(left, right));
}

int getJustBigger(Node *root, int target)
{
    if (!root)
        return INT_MAX;

    if (root->data < target)
    {
        return getJustBigger(root->right, target);
    }

    int left = getJustBigger(root->left, target);
    int right = getJustBigger(root->right, target);
    int val = (root->data == target) ? INT_MAX : root->data;
    return min(val, min(left, right));
}

void inOrderPreAndSucc_m2(Node *root, int node)
{
    if (!root)
        return;

    // predeccessor -> maximum element in left subtree
    // successor -> minimum element in right subtree
    // becuz  in left side all elements are in decreasing order and
    // in right side all elements are in increasing order
    // just see the example and you will understand it

    int predeccsor = getJustSmaller(root, node);
    int successor = getJustBigger(root, node);

    cout << "predeccessor " << predeccsor << endl;
    cout << "successor " << successor << endl;
}

int main()
{
    Node *root = NULL;
    // i/p : 10 5 20 2 8 4 6 11 25 17 15 -1
    // in order 2 4 5 6 10 11 15 20 25
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    cout << "printing the tree " << endl;
    LevelOrder(root);
    // inOrderPreAndSucc_m1(root, 11);
    inOrderPreAndSucc_m2(root, 25); // 10 15

    return 0;
}
