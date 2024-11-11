#include <iostream>
#include <vector>
/*
Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: 1
Explanation: Here there exists a subset with sum = 9, 4+3+2 = 9.

Input: n = 6, arr[] = {3, 34, 4, 12, 5, 2} , sum = 30
Output: 0
Explanation: There is no subset with sum 30.

*/

using namespace std;

bool solveRec(int arr[], int &n, int &sum, int currSum, int i)
{
    // base case
    if (i >= n)
    {
        return false;
    }

    if (currSum == sum)
    {
        return true;
    }

    // include
    bool include = solveRec(arr, n, sum, currSum + arr[i], i + 1);

    // exclude
    bool exclude = solveRec(arr, n, sum, currSum + 0, i + 1);

    return (include || exclude);
}

bool solveMemo(int arr[], int n, int &sum, int currSum, vector<vector<int>> &dp)
{

    // base case
    if (n <= -1 || currSum > sum)
    {
        return false;
    }

    if (currSum == sum)
    {
        return true;
    }

    // step 3 check if ans exist

    if (dp[n][currSum] != -1)
    {
        return dp[n][currSum];
    }

    // include
    bool include = solveMemo(arr, n - 1, sum, currSum + arr[n], dp);
    if (include)
        return true;
    // exclude

    bool exclude = solveMemo(arr, n - 1, sum, currSum + 0, dp);

    // step 2 dp me store karo
    dp[n][currSum] = (include || exclude);
    return dp[n][currSum];
}


int main()
{
    int arr[] = {3, 34, 4, 12, 5, 2};
    int n = 6;
    // int sum = 9;
    int sum = 30;

    // bool ans = solveRec(arr, n, sum, 0, 0);

    // memoization

    // step 1 : dp array create karo
    // n or currsum dono change ho rahe hai --> 2d dp hai
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    bool ans = solveMemo(arr, n - 1, sum, 0, dp);
    if (ans)
    {
        cout << "Subset sum exists" << endl;
    }
    else
    {
        cout << "Subset sum Doesn't exist" << endl;
    }

    return 0;
}