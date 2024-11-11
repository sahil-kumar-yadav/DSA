#include <iostream>
#include <vector>

using namespace std;

// int findMaxRob(int arr[], int n, int i, int sum)
// {
//     // base case
//     if (i > n - 1)
//     {
//         return sum;
//     }

//     // include -> i.e rob
//     int rob = findMaxRob(arr, n, i + 2, sum + arr[i]);

//     // exclude -> i.e not rob
//     int Notrob = findMaxRob(arr, n, i + 1, sum);

//     return max(rob, Notrob);
// }

int solveRecur(int arr[], int n)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];

    int RobCurr = solveRecur(arr, n - 2) + arr[n];
    int DontRobCurr = solveRecur(arr, n - 1);

    return max(RobCurr, DontRobCurr);
}

int solveMemo(int arr[], int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return arr[0];

    // step 3 check if ans is already present
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int RobCurr = solveMemo(arr, n - 2, dp) + arr[n];
    int DontRobCurr = solveMemo(arr, n - 1, dp);

    // step 2 store in dp array
    dp[n] = max(RobCurr, DontRobCurr);
    return dp[n];
}

int solveTab(int arr[], int n)
{
    // step 1: create dp array
    vector<int> dp(n + 1, -1);

    // step 2: observe base case and intial value of dp
    dp[0] = arr[0];
    dp[1] = arr[1];

    // step 3 apply same recursive logic

    for (int i = 2; i <= n; i++)
    {

        // current include
        int include = dp[i - 2] + arr[i];
        // exclude current
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }

    return dp[n];
}

int main()
{
    int arr[] = {1, 2, 3, 1};
    int n = 4;

    // int ans = findMaxRob(arr, n, 0, 0);
    // int ans = solveRecur(arr, n);

    // memoization
    // step 1 create dp array

    // vector<int> dp(n + 2, -1);
    // int ans1 = solveMemo(arr, n - 1, dp);

    int ans2 = solveTab(arr, n);

    cout << "maximum Robbed money is " << ans2 << endl;

    return 0;
}