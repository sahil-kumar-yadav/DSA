#include <iostream>

using namespace std;

int findMinimumElement(int arr[], int n, int target)
{
    // base case
    if (target < 0)
    {
        return INT_MAX;
    }
    if (target == 0)
    {
        return 0;
    }

    //
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = findMinimumElement(arr, n, target - arr[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int target = 11;

    int ans = findMinimumElement(arr, n, target);
    cout << "ans " << ans << endl;

    return 0;
}