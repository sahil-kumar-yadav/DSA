#include <iostream>
#include <vector>

using namespace std;

void mergeTwo(int arr1[], int n1, int arr2[], int n2)
{

    vector<int> ans(n1 + n2, 0);

    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            ans[k] = arr1[i];
            i++;
        }
        else
        {
            ans[k] = arr2[j];
            j++;
        }
        k++;
    }
    cout<<"i "<<i<<" j "<<j<<endl;

    while (i < n1)
    {
        cout<<"i "<<i<<" k "<<k<<endl;
        ans[k] = arr1[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        cout<<"j "<<j<<" k "<<k<<endl;
        ans[k] = arr2[j];
        j++;
        k++;
    }
    cout << "Printing merged array" << endl;
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

int main()
{
    // int arr1[] = {1, 3, 4, 5};
    int arr1[] = {5,8,9};
    int n1 = 3;
    // int arr2[] = {2, 4, 6, 8};
    int arr2[] = {4,7,8};
    int n2 = 3;
    mergeTwo(arr1, n1, arr2, n2);
    return 0;
}