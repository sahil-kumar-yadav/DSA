# build Tree
```cpp
#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data = data;
        left = NULL;
        right = NULL;

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
int main(){
    Node *root = buildTree();
    return 0;

}
```

# Pre Order Traversal

```cpp
void preOrderTraversal(Node *root){
    if(!root)
        return ;

    // LCR
    preOrderTraversal(root->left);
    cout<<root->data<<" ";
    preOrderTraversal(root->right);
}
```

# In Order Traversal

```cpp
void InOrderTraversal(Node *root){
    if(!root)
        return ;

    // CLR
    cout<<root->data<<" ";
    InOrderTraversal(root->left);
    InOrderTraversal(root->right);
}
```

# Post Order Traversal
```cpp
void PostOrderTraversal(Node *root){
    if(!root)
        return ;

    // LRC
    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->data<<" ";
}

```
# level Order Traversal

```cpp
void LevelOrder(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();

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

```
# level Order Traversal In new Line
-  after first level push null for new line
- and if q not empty and front node is null that means lvl complete , so push NULL

```cpp
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


```

# height of tree
```cpp
int height(Node *root){
    if(!root){
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight,rightHeight) + 1;
}
```
# Diameter of tree
```cpp
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

```
# check balance tree or not
```cpp


bool isBalanced(Node *root)
{
    // tree is balanced if height of left and right is differ by one

    if (root == NULL)
    {
        return true;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }

    bool leftAns = isBalanced(root->left);
    bool rightAns = isBalanced(root->right);

    return (leftAns && rightAns);
}

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```

```cpp

```