#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <map>
// #include <pair>
using namespace std;

bool cmp(int &a, int &b)
{
    return (a < b);
}

int main()
{
    int arr[] = {-1, 2, -1, 2, 99};
    int n = 5;
    int k = 99;
    // map<int, int,greater<int>> mp;
    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int size = mp.size();
    cout << mp.size() << endl;
    int sum = 0;
    for (auto it : mp)
    {
        cout << it.first << " -> ";
        cout << it.second;
        sum += it.second;
        cout << endl;
    }
    int percentage = (mp[k] / (sum * 1.0)) * 100;
    cout << percentage << endl;

    return 0;
}