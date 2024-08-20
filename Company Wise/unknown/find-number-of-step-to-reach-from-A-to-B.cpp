#include <iostream>
#include <climits>   // For INT_MAX
#include <algorithm> // For min
#include<vector>

using namespace std;

int findMin(int &target, int &start, int sum, int steps,vector<int>&dp)
{
    // Base case
   
    if (sum < start || sum > target)
    {
        return INT_MAX;
    }
    if (sum == target)
    {
        return steps;
    }

    if(dp[sum] != INT_MAX){
        return dp[sum];
    }

    // Recursive calls
    int add = findMin(target, start, sum + 3, steps + 1,dp);

    int sub = INT_MAX;
    if(add > target){
        sub = findMin(target, start, sum - 2, steps + 1,dp);
    }

    // Return the minimum of the two paths
    dp[sum] =  min(add, sub);
    return dp[sum];
}

int main()
{
    int target = 10; // Target value to reach
    int start = 0;
    int sum = start;     // Starting value
    vector<int>dp(sum+10,INT_MAX);
    int minSteps = findMin(target, start, sum, 0,dp); // Find minimum steps to reach target
    cout << "Minimum steps to reach " << target << " from " << start << " is: " << minSteps << endl;


    return 0;
}
