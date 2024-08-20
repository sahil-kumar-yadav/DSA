#include <iostream>
#include<vector>

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

void pathSum(Node *root, int sum, vector<int> &ans)
{
    if (!root)
    {
        return;
    }

    // check karo leaf hai kya

    if (root->left == NULL && root->right == NULL)
    {
        // leaf node py hai
        sum += root->data;
        ans.push_back(sum);
    }

    // root node nahi hai
    // node ki value add karke left and right my search karo
    sum+= root->data;
    pathSum(root->left, sum, ans);
    pathSum(root->right, sum, ans);
}

int main()
{
    // 5 4 11 7 -1 -1 2 -1 -1 -1 8 13 -1 -1 4 5 -1 -1 1 -1 -1
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    vector<int> ans;
    pathSum(root,0,ans);
    cout << endl;
    cout << "Printing ans " << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}