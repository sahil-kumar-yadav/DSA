#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<long long int> &arr){
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
void reverse(vector<long long int> &arr, int k, int s, int e)
{
    int n = arr.size();
    // cout<<"s "<<s<<" e "<<e<<endl;
    if (s >= e)
        return;

    int i = s, j = e;

    // swap k

    while (i < j && (i < n && j < n))
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
    // cout<<" after reverse "<<endl;
    // printArray(arr);
    // call for next
    s = s+k;
    e = (e+k<n)?e+k:n-1;
    reverse(arr, k, s ,e);
}

int main()
{
    vector<long long> arr{5, 4, 3, 2, 1};
    int n = arr.size();
    int k = 6;
    if(k>n){
        k = n;
    }
   
   
    reverse(arr, k, 0, k - 1);
    cout<<"finally "<<endl;
    printArray(arr);

    return 0;
}