#include <iostream>
#include<vector>

using namespace std;

int findMaxNonAdjecentDP(vector<int>&arr, int n, int i,vector<int>&dp)
    {
        if (i >= n)
            return 0;
        
        if(dp[i] != -1){
            return dp[i];
        }
        
        int include = findMaxNonAdjecentDP(arr, n, i + 2,dp) + arr[i];
        int exclude = findMaxNonAdjecentDP(arr, n, i + 1,dp)+0;
        
        dp[i] = max(include, exclude);
        return dp[i];
    }
    

int findMaxNonAdjecent(int arr[], int n, int i, int sum,vector<int>&dp)
{
    cout<<"i "<<i<<" Sum "<<sum<<endl;
    if (i >= n)
        return sum;

    if(dp[i] != -1)
    {
        return dp[i];
    }
    
    int include = findMaxNonAdjecent(arr, n, i + 2, sum + arr[i],dp);
    int exclude = findMaxNonAdjecent(arr, n, i + 1, sum,dp);

    dp[i] = max(include, exclude);
    return  dp[i];
}

int main()
{
    int arr[] = {1,2,4,9};
    int n = 4;
    vector<int>dp(n+1,-1);
    int ans = findMaxNonAdjecent(arr, n, 0, 0,dp);
    cout << "ans " << ans;

    return 0;
}