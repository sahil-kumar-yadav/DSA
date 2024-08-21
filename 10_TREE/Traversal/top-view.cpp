#include <iostream>
#include <map>
#include <set>

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

void topView(Node *root, int d, set<int, int> &st)
{
    if (!root)
        return;

    // entry karo
    st.insert({d, root->data});

    // left jao
    topView(root->left, d - 1, st);

    // right jao
    topView(root->right, d + 1, st);
}

int main()
{
    // 1 2 3 -1 -1 4 6 -1 -1 -1 90 5 -1 7 -1 -1 8 -1 -1
    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    set<pair<int, int>> st;
    // topView(root, 0, st);
    // cout << "Printing map " << endl;
    // for (auto it : st)
    // {
    //     cout << it[0] << " -> ";
    //     cout << it[1] << endl;
    // }
    return 0;
}