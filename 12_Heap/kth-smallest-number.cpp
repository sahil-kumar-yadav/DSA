#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int arr[] = {3, 4, 9, 7, 1}; // 1 ,3 ,4  7, 9
    int n = 5;
    int k = 3;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // using minHeap

    // for (int i = 0; i < n; i++)
    // {
    //     minHeap.push(arr[i]);
    // }

    // while(--k){
    //     minHeap.pop();
    // }

    // cout << "kth smallest number is " << minHeap.top();

    // using maxheap
    
    for (int i = 0; i < k; i++)
    {
        maxHeap.push(arr[k]);
    }

    for (int i = k; i < n; i++)
    {
        int newelement = arr[i];
        if (newelement < maxHeap.top() )
        {
            maxHeap.pop();
            maxHeap.push(newelement);
        }
    }

    cout<<"kth minimum element is "<<maxHeap.top()<<endl;

    return 0;
}