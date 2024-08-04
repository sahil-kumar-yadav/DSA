#include <iostream>

using namespace std;

void findMax(int arr[], int n, int i, int &maxi)
{
    if (i == n)
    {
        return;
    }
    maxi = max(arr[i], maxi);
    findMax(arr, n, i + 1, maxi);
}

int main()
{
    int arr[] = {10, 30, 15, 21, 44, 26};
    int n = 6;
    int maxi = -1;
    findMax(arr, n, 0, maxi);
    cout << "maximum is " << maxi << endl;

    return 0;
}