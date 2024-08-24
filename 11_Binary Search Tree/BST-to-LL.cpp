#include <iostream>
#include <queue>

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

void ConvertToLL(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }
    // cout << "at node " << root->data << endl;
    if (head)
    {
        // cout << "head " << head->data << endl;
    }
    ConvertToLL(root->right, head);
    root->right = head;
    head = root;
    ConvertToLL(root->left, head);
    // doublly ll ky liye reverse bhi lagana padega
    if (head != NULL)
    {
        // doublly ll
        head->left = root;
    }

    root->left = NULL;
}

int main()
{
    // i/p : 100 50 200 20 70 60 200 150 250 170 -1

    Node *root = NULL;
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    // cout << "printing the tree " << endl;
    Node *head = NULL;
    ConvertToLL(root, head);

    cout << "Printing LL " << endl;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->right;
    }

    return 0;
}