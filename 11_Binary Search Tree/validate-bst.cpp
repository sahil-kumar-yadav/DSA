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

Node* buildTree(){
    int data;
    cout<<"Enter data for node ";
    cin>>data;

    if(data == -1){
        return NULL;
    }

    Node* root = new Node(data);

    cout<<"Enter data for "<<data<< "left ";
    root->left = buildTree();

    cout<<"Enter data for "<<data<< "right ";
    root->right = buildTree();

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

 // 100 50 25 -1 -1 75 -1 -1 150 125 -1 -1 200 -1 -1 // valid
    // 100 250 25 -1 -1 75 -1 -1 150 125 -1 -1 200 -1 -1 // invalid
bool validateBST(Node *root,int lowerbound,int upperbound){
    if(root == NULL){
        return true;
    }

    if(root->data < upperbound && root->data > lowerbound){
        // uppernode uperbound
        // root node --> lowerbound <  data   < upperbound 
        // lower node lowebound
        // sabh sahi hai

        // left side my ja rahe hai upperbound update karna padega
        bool leftans = validateBST(root->left,lowerbound,root->data);
        // right side my ja rahe hai lowerbound update karna padega
        bool rightans = validateBST(root->right,root->data,upperbound);

        return (leftans && rightans) ;
    }
    else{
        // valid nahi
        return false;
    }


}

int main()
{
    // 100 50 25 -1 -1 75 -1 -1 150 125 -1 -1 200 -1 -1 // valid
    // 100 250 25 -1 -1 75 -1 -1 150 125 -1 -1 200 -1 -1 // invalid
    Node *root = NULL;
    root = buildTree();
    
    cout << "printing the tree " << endl;
    LevelOrder(root);
    int lowerBound = -2147483646;
    int uperBound = 2147483647;
    bool ans = validateBST(root,lowerBound,uperBound);

    if(ans){
        cout<<"valid BST "<<endl;
    }
    else{
        cout<<"Invalide BST"<<endl;
    }

    return 0;
}

