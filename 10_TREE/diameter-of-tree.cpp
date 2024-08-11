#include <iostream>
#include <queue>
#include<algorithm>

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
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    Node *root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int height(Node *root){
    if(!root){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight,rightHeight) + 1;
}

int diameter(Node* root) {

        if (root == NULL) {
            return 0;
        }

        // ya to diameter left my hoga
        // ya fir right my
        // ya fir left + root + right milleke

        int opt1 = diameter(root->left);
        int opt2 = diameter(root->right);
        int opt3 = height(root->left) + 1 + height(root->right);
        int ans = max(opt1, max(opt2, opt3)); // maximum of 3

        return ans-1; // -1 for edges 
    }

int main()
{
    // input 10 20 30 -1 -1 50 -1 -1 40 -1 60 70 -1 -1 80 -1 -1
    Node *root = buildTree();

    int Treediameter = diameter(root);
    cout<<"diameter is "<<Treediameter<<endl;
    return 0;
}