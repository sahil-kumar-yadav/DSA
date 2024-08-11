#include <iostream>
#include <vector>
#include<stack>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int x)
    {
        this->data = x;
        this->next = NULL;
    }
};

void printLL(Node *root)
{

    Node *temp = root;

    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}


// void findNextGreater(Node *head, vector<int> &ans){
//     if (!head)
//         return;
    
//     stack<int>st;

//     Node *temp = head;

//     while(temp){
//         st.push(temp->data);
//         temp = temp->next;
//     }

//     int maxi = 0;

//     while(!st.empty()){
        
//         if(maxi>st.top()){
//             ans.push_back(maxi);
           
//         }
//         else{
//             ans.push_back(0);
//             maxi = st.top();
//         }
//         st.pop();
//     }

//     cout<<"Printing ans"<<endl;

//     for(auto it:ans){
//         cout<<it<<" ";
//     }

// }

void findNextGreater(Node *head){
    if (!head)
        return;

    vector<int>ll;
    
    stack<int>st;

  
    while(head){
        ll.push_back(head->data);
        head = head->next;
    }
    int n = ll.size();
    vector<int> ans(n,0);
    for(int i = 0;i<n;i++){
        while(!st.empty() && ll[i] > ll[st.top()]){
            int index = st.top();
            ans[index] = ll[i];
            st.pop();
        }
        st.push(i);
    }

    cout<<"Printing ans"<<endl;

    for(auto it:ans){
        cout<<it<<" ";
    }

}




int main()
{
    Node *head = new Node(2);
    head->next = new Node(1);
    head->next->next = new Node(5);
    // head->next->next->next = new Node(3);
    // head->next->next->next->next = new Node(5);
    // head->next->next->next->next->next = new Node(6);
    // head->next->next->next->next->next->next = new Node(7);
    printLL(head);
    
    findNextGreater(head);

    return 0;
}