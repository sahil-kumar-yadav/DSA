#include <iostream>
#include <map>


using namespace std;

int findUniqueHashing(int a[], int n, int k)
{
    int ans = -1;

    map<int,int>freqMap; // Create an unordered_map to store frequency

    // Populate the frequency map
    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        freqMap[num]++; // Increment the frequency of the current element
    }

    for (auto it : freqMap)
    {
        // cout<<it.first<<"-> "<<it.second<<endl;
        if (it.second % k != 0)
        { // not multiple of k
            ans = it.first;
            break;
        }
    }

    return ans;
}

void findUnique(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i]; // xor
    }

    cout << "unique element is " << ans << endl;
}

int main()
{
    int arr[] = {6, 2, 5, 2, 2, 6, 6};
    int n = 7;

    // findUnique(arr, n);
    // another method
    // Hasing use map

    int ans = findUniqueHashing(arr,n,3);
    cout<<"ans is " <<ans<<endl;

    return 0;
}