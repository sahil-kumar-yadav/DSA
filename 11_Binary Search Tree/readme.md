# Binary Search tree
- binary search
- [ 2 4 {6} 8 10 ] 6 mid hai 6 ke left my smaller element hai right my bigger
- similary for Binary search tree all elment of left side are smaller and all element greater than node are in right side


# Create BST (Binary Search Tree)

```cpp
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

int main()
{
    Node *root = NULL;
    cout << "Enter the data for Node " << endl;
    takeInput(root);

    cout << "printing the tree " << endl;
    LevelOrder(root);

    return 0;
}

```
# InOrder of BST
```cpp
void InOrder(Node *root){
    if(root == nullptr){
        return;
    }

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}


```

# Search In BST

```cpp

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



```
# Maximum and minimum in BST
```cpp
int findMaximumItrative(Node *root){

    if(root == nullptr){
        cout<<"tree empty "<<endl;
        return -1;
    }

    // iterate to right till right exist

    Node *temp = root;
    while(temp->right){
        temp = temp->right;
    }

    
    return temp->data;
}


```
```cpp
int findMinimumItrative(Node *root){

    if(root == nullptr){
        cout<<"tree empty "<<endl;
        return -1;
    }

    // iterate to right till right exist

    Node *temp = root;
    while(temp->left){
        temp = temp->left;
    }

    return temp->data;
}

```
```cpp
int findMaximumRecursive(Node *root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }

    if(root->right){
        ans = findMaximumRecursive(root->right);
    }
    else{
        ans =  root->data;
    }

    return ans;
}

```

```cpp
int findMinimumRecusive(Node *root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }

    if(root->left){
        ans = findMinimumRecusive(root->left);
    }
    else{
        ans =  root->data;
    }

    return ans;
}

```

# validate BST 
```cpp
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


```

```cpp

```

```cpp

```

```cpp

```