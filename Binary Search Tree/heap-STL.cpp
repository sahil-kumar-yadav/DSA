#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int main(){

    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    
    maxHeap.push(10);
    maxHeap.push(1);
    maxHeap.push(13);
    maxHeap.push(199);
    maxHeap.push(3);
    maxHeap.push(7);
    maxHeap.push(8);

    minHeap.push(10);
    minHeap.push(1);
    minHeap.push(13);
    minHeap.push(199);
    minHeap.push(3);
    minHeap.push(7);
    minHeap.push(8);

    cout<<"printing maxheap "<<endl;
    while(!maxHeap.empty())
    {
        cout<<maxHeap.top()<<" ";
        maxHeap.pop();
    }
    cout<<endl;
    cout<<"printing minHeap "<<endl;
    while(!minHeap.empty())
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
    

    return 0;

}


