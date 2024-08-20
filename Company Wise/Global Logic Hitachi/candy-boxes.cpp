#include <iostream>
#include <vector>
#include<queue>

using namespace std;

void findbeautifulCount_brut(int boxes[],int n,vector<pair<int, int>> &queries,int q,vector<int>&ans){
    
    for(int i = 0;i<q;i++){
        auto it = queries[i];
        int startIndex = it.first-1;
        int endingIndex = it.second-1;
        priority_queue<int>MaxHeap;
        while(startIndex <= endingIndex){
            MaxHeap.push(boxes[startIndex++]);
        }

        int firstMax = MaxHeap.top();
        MaxHeap.pop();
        int secondMax = MaxHeap.top();

        int avg = (firstMax + secondMax)/2;
        ans.push_back(avg);
    }
}
int main()
{
    int n = 4;
    // int boxes[] = {2, 5, 2, 3};
    int boxes[] = {1,2,3,4};
    int q = 4;
    vector<pair<int, int>> queries = {
        {1, 4},
        {1, 2},
        {2, 3},
        {3, 4}};
    vector<int>ans;
    findbeautifulCount_brut(boxes,n,queries,q,ans);

    cout<<"Printing ans "<<endl;
    for(auto it:ans){
        cout<<it;
        cout<<endl;
    }

    return 0;
}