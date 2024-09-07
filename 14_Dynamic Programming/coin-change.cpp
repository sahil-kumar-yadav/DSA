#include <iostream>
#include <vector>
using namespace std;

int recursol(int arr[], int n, int target)
{
    // base case
    if (target < 0)
        return INT_MAX;

    if (target == 0)
        return 0;

    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int ans = recursol(arr, n, target - arr[i]);
        mini = min(mini, ans);
        if (mini == 0)
            break; // isse minimum nahi ho skta break karlo yahi
    }

    return mini != INT_MAX ? mini + 1 : -1;
}

int topDown(int arr[], int n, int target, vector<int> &dp)
{
    // base case
    if (target < 0)
        return INT_MAX;

    if (target == 0)
        return 0;

    // step 2 if ans already present

    if (dp[target] != INT_MAX)
    {
        return dp[target];
    }
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        int ans = topDown(arr, n, target - arr[i], dp);
        mini = min(mini, ans);
        if (mini == 0)
            break; // isse minimum nahi ho skta break karlo yahi
    }

    dp[target] = mini + 1;
    return dp[target];
}

int main()
{
    int arr[] = {1, 2, 5};
    int n = 3;
    int target = 3;

    // int ans = recursol(arr, n, target);

    // step 1 create dp array
    vector<int> dp(target + 2, INT_MAX);
    int ans = topDown(arr, n, target, dp);

    cout << "minimum number of coins to reach target sum is " << ans << endl;

    return 0;
}