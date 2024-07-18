#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int data;
    // cout<<"Enter data for node "<<endl;;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    // cout<<data<< "left ";
    root->left = buildTree();
    root->right = buildTree();

    // cout<<data<< "right ";

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


void convertIntoSumTree(Node *root,int leftsum,int rightsum){
    if(!root){
        return;
    }
    if(!(root->left) && !(root->right) ){
        return;
    }

    
    convertIntoSumTree(root->left,leftsum,rightsum);
    convertIntoSumTree(root->right,leftsum,rightsum);

    if(root->left){
        leftsum = root->left->data;
    }
    if(root->right){
        rightsum = root->right->data;
    }
    root->data += leftsum + rightsum;
}

int main()
{
    // input 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
    Node *root = buildTree();
    int leftsum,rightsum;
    if(root->left){
        leftsum = root->left->data;
    }
    if(root->right){
        rightsum = root->right->data;
    }
    // root->data = leftsum + rightsum;
    convertIntoSumTree(root,leftsum,rightsum);
    LevelOrder(root);
    return 0;
}