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

```cpp

```