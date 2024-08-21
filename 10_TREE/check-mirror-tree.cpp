#include <iostream>
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

bool checkmirror(Node *p, Node *q)
{
    if (!p && !q)
        return true;

    if (p && q)
    {
        if (p->data == q->data)
        {
            cout<<p->data<<" "<<q->data<<endl;
            bool left = checkmirror(p->left, q->right);
            bool right = checkmirror(p->right, q->left);
            return (left & right);
        }
        return false;
    }

    return false;
}

int main()
{
    //  1 2 3 -1 -1 4 -1 -1 2 4 -1 -1 3 -1 -1
    

    Node *root = buildTree();
    cout << "Printing the Inorder of tree" << endl;
    InOrderTraversal(root);
    cout<<endl;
    bool ans = checkmirror(root->left, root->right);
    cout << "tree are mirror " << ans << endl;

    return 0;
}