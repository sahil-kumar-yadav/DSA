#include <iostream>
#include <vector>

using namespace std;

int recurSol(int n)
{
    if (n == 0 || n == 1)
        return n;

    int ans = recurSol(n - 1) + recurSol(n - 2);

    return ans;
}

int topDown(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = topDown(n - 1, dp) + topDown(n - 2, dp);

    return dp[n];
}

int bottomUp(int n)
{
    // step 1 create dp array
    vector<int> dp(n + 1, 0);

    // step 2 observe base case and intialize dp
    dp[0] = 0;
    dp[1] = 1;

    // step 3 check building logic
    // usme n--> 0 ja rahe the isme 2 --> n ja rahe hai

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main()
{
    // 0 1 1 2 3 5 8 13 21
    int n = 8;

    int ans = recurSol(n);

    cout << "nth fibbonacci is " << ans << endl;

    // approch 1 : TopDown approch or memoization // recursive approch

    // step 1 create dp array
    // step 2 ans ko dp me store karo
    // step 3 base case ke just baad check karo ans already present hai ya nahi

    vector<int> dp(n + 1, -1);

    int ans1 = topDown(n, dp);

    cout << "nth fibbonacci is " << ans1 << endl;

    // approch 2 : Bottom up approch // iterative approch [0 -> n]

    // step 1 : create dp array
    // step 2 : observe base case and intialize dp array accordingly
    // step 3 : check building locgic

    int ans3 = bottomUp(n);
    cout << "nth fibbonacci is " << ans3 << endl;

    return 0;
}