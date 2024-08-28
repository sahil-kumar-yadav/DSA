#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int arr[] = {12, 3, 5, 7, 19, 15, 1, 10};
    int n = 8;
    sort(arr, arr + n);
    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(arr[i] - arr[i + 1]);
        mini = min(mini, diff);
    }

    cout << "minimum difference is " << mini << endl;

    return 0;
}