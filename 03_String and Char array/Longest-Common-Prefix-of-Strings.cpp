#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printArr(vector<string> &arr)
{
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
}

bool checkInAll(vector<string> arr, string &str)
{

    for (auto it : arr)
    {
        // cout << "it " << it << " str " << str << endl;
        size_t found = it.find(str);
        if (found == string::npos ||  found != 0)
        {
            // cout << str << " not found in " << it;
            return false;
        }
    }
    return true;
}

int main()
{
    // vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    vector<string> arr = {"ol" ,"xozic"};
    int n = arr.size();

    printArr(arr);
    int smallestIndex = 0;
    int len = arr[0].length();
    for (int i = 0; i < n; i++)
    {
        string str = arr[i];
        if (str.length() < len)
        {
            len = str.length();
            smallestIndex = i;
        }
    }

    string smallest = arr[smallestIndex];
    cout << smallest << endl;
    // int strlen = smallest.length();
    cout << "Now ans" << endl;
    for (int i = smallest.length() - 1; i >= 0; i--)
    {
        string newstr = smallest.substr(0, i + 1 - 0);
        cout << "newstr " << newstr << endl;
        if (checkInAll(arr, newstr))
        {
            cout << newstr << " --" << endl;
        }
    }

    return 0;
}