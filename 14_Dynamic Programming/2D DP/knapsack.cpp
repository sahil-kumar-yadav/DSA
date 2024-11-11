#include <iostream>
#include <vector>
using namespace std;

int solveRecur(int capacity, vector<int> &weight, vector<int> &values, int i)
{
    // base case
    if (i >= weight.size() || capacity < 0)
    {
        return 0;
    }

    // include
    int include = 0;
    if (capacity - weight[i] >= 0)
    {
        include = solveRecur(capacity - weight[i], weight, values, i + 1) + values[i];
    }

    // exclude
    int exclude = solveRecur(capacity, weight, values, i + 1);

    return max(include, exclude);
}

int solveMemo(int capacity, vector<int> &weight, vector<int> &values, int i, vector<vector<int>> &dp)
{
    // base case
    if (i >= weight.size() || capacity < 0)
    {
        return 0;
    }

    if (dp[i][capacity] != 0)
    {
        return dp[i][capacity];
    }
    // include
    int include = 0;
    if (capacity - weight[i] >= 0)
    {
        include = solveMemo(capacity - weight[i], weight, values, i + 1, dp) + values[i];
    }

    // exclude
    int exclude = solveMemo(capacity, weight, values, i + 1, dp);

    dp[i][capacity] = max(include, exclude);

    // intialization dekho
    return dp[i][capacity];
}

int main()
{
    //     4
    // 6 3 8 6 9 8 2 4 10 9
    // 2 1 3 1 4 1 2 2 5 7

    int w = 4;
    vector<int> weight = {2, 1, 3, 1, 4, 1, 2, 2, 5, 7};
    vector<int> values = {6, 3, 8, 6, 9, 8, 2, 4, 10, 9};

    int ans = solveRecur(w, weight, values, 0);
    int n = weight.size();

    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    int ans1 = solveMemo(w, weight, values, 0, dp);

    // tablualtion method karna hai
    
    // space optimization -- sirf 2 vector array sy ho jayega
    cout << "ans " << ans << endl;
    cout << "ans " << ans1 << endl;

    return 0;
}