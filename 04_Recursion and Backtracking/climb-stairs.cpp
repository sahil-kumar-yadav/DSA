#include <iostream>

using namespace std;

int countWays(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    int ans = countWays(n - 1) + countWays(n - 2);

    return ans;
}

void countWaysApprochTwo(int n, int i, int &ways)
{
    if (i >= n)
        return;

    if (i == n-1)
    {
        ways++;
        return;
    }

    countWaysApprochTwo(n, i + 1, ways);
    countWaysApprochTwo(n, i + 2, ways);
}
int minSteps(int n, int i, int step)
{
    if (i > n)
    {
        return INT_MAX;
    }
    if (i == n)
    {
        return step;
    }

    // ya to ek step lo ya 2 step lo
    int ekStep = minSteps(n, i + 1, step + 1);
    int twoStep = minSteps(n, i + 2, step + 1);

    return min(ekStep, twoStep);
}
int main()
{

    int n = 19; // bigger input

    // int ans = minSteps(n, 0, 0);
    int ans = countWays(n);
    int totalWays = 0;
    countWaysApprochTwo(n, 0, totalWays);
    cout << "ans " << ans << endl;
    cout << "total ways " << totalWays << endl;

    return 0;
}