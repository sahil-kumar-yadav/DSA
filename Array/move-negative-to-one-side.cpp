#include <iostream>

using namespace std;

void moveNegative(int arr[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        bool cond1 = (arr[i] < 0); // positive numbe
        bool cond2 = (arr[j] > 0); // negative number

        if (cond1)
        {
            i++; // positive number in front
        }

        if (cond2)
        {
            j--; // negative number in the end
        }

        if (!cond1 && !cond2)
        {
            swap(arr[i], arr[j]);
        }
    }

}

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {2, -3, -1, 5, -4};
    int n = 5;
    moveNegative(arr, n);
    printArr(arr, n);

    return 0;
}