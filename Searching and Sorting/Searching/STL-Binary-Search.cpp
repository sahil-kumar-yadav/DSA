#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    int target = 3;
    int ans = binary_search(arr, arr + n, target); // true false return karta hai
    if (ans)
    {
        cout << lower_bound(arr, arr + n, target) - arr; // first occ return karta hai
        // cout << lower_bound(arr1.begin(), arr1.end(), 20) - arr1.begin(); 
    }
    

    return 0;
}