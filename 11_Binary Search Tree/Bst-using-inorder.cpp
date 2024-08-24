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

Node* createBSTusingInorder(int inorder[],int s,int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;

    Node *root = new Node(inorder[mid]);

    // left bst 
    root->left = createBSTusingInorder(inorder,s,mid-1);

    // right bst
    root->right = createBSTusingInorder(inorder,mid+1,e);
    
    return root;
}

int main()
{
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s = 0,e = 8;
    Node *root = createBSTusingInorder(inorder,s,e);

    cout << "printing the tree " << endl;
    LevelOrder(root);

    return 0;
}
