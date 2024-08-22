#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>

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

void ZigZag(Node *root, vector<int> &ans)
{
    if (!root)
        return;

    // level order traversal karna padega
    queue<Node *> q;

    q.push(root);
    q.push(NULL);

    bool isreverse = false;

    while (!q.empty())
    {

        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
        }
        else
        {
            vector<int> temp;
            while (q.front() != NULL && !q.empty())
            {
                Node *frontNode = q.front();
                q.pop();
                temp.push_back(frontNode->data);
                cout << frontNode->data << " ";
                if (frontNode->left)
                {
                    q.push(frontNode->left);
                }
                if (frontNode->right)
                {
                    q.push(frontNode->right);
                }
            }

            if (isreverse)
            {
                reverse(temp.begin(), temp.end());
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            else
            {
                ans.insert(ans.end(), temp.begin(), temp.end());
            }
            q.push(NULL);
            isreverse = !isreverse;
        }
    }
}

int main()
{
    // 3 9 -1 -1 20 15 26 -1 -1 19 -1 -1 7 -1 -1
    // 3
    // 9  20
    // 15 7
    // 26 19

    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    cout << endl;
    vector<int> ans;
    ZigZag(root, ans);
    cout << endl;
    cout << "Printing ans " << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}