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

bool searchInBST(Node *root,int target){
    if(root == NULL){
        return false;
    }

    int rootData = root->data;

    if(target == rootData){
        return true;
    }
    bool leftSearch = false,rightSearch = false;
    if(target > rootData){
        // search in right
        rightSearch = searchInBST(root->right,target);
    }
    else{
        // search in left
        rightSearch = searchInBST(root->left,target);
    }

    return (leftSearch ||rightSearch);
}


int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    cout << "printing the tree " << endl;

    // i/p : 10 5 20 2 8 4 6 11 25 17 15 -1
    int target = 40;
    bool checkTarget = searchInBST(root,target);

    if(checkTarget){
        cout<<"target found"<<endl;
    }
    else{
        cout<<"target not found"<<endl;
    }

    return 0;
}



