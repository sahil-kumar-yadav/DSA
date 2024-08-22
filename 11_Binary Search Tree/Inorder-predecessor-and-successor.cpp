#include <iostream>
#include <queue>
#include <vector>

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

    return findNode(root->left, target);
}

pair<int, int> getMinMax(Node *root)
{

    if (!root)
        return (INT_MIN, INT_MAX);

    pair<int, int> p = getMinMax(root->left);

    return {max(p.first, root->data), min(p.second, root->data)};
}

void inOrderPreAndSucc_m2(Node *root, int node)
{
    if (!root)
        return;

    Node *mainNode = findNode(root, node);

    // predeccessor -> maximum element in left subtree
    // successor -> minimum element in right subtree
    // becuz  in left side all elements are in decreasing order and
    // in right side all elements are in increasing order
    // just see the example and you will understand it

    pair<int, int> p = getMinMax(root->left);
    int predeccsor = p.first;
    int successor = p.second;

    cout << "predeccessor " << predeccsor << endl;
    cout << "successor " << successor << endl;
}

int main()
{
    Node *root = NULL;
    // i/p : 10 5 20 2 8 4 6 11 25 17 15 -1
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    cout << "printing the tree " << endl;
    LevelOrder(root);
    // inOrderPreAndSucc_m1(root, 11);
    inOrderPreAndSucc_m2(root, 11); // 10 15

    return 0;
}
