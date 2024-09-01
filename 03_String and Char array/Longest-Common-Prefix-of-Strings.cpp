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
        if (it.size() < str.size())
            return false;
        size_t found = it.find(str);
        if (found == string::npos || found != 0)
        {
            // cout << str << " not found in " << it;
            return false;
        }
    }
    return true;
}

string longestCommonPrefix(vector<string> &arr)
{
    int n = arr.size();

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

    // string smallest = arr[smallestIndex];
    string smallest = arr[0];
    // cout << smallest << endl;
    // int strlen = smallest.length();

    // cout << "Now ans" << endl;
    for (int i = smallest.length() - 1; i >= 0; i--)
    {
        string newstr = smallest.substr(0, i + 1 - 0);
        // cout << "newstr " << newstr << endl;
        if (checkInAll(arr, newstr))
        {
            // cout << newstr << " --" << endl;
            return newstr;
            break;
        }
    }

    return "";
}

int main()
{
    // vector<string> arr = {"geeksforgeeks", "geeks", "geek", "geezer"};
    // vector<string> arr = {"ol" ,"xozic"};
    // vector<string> arr = {"flower", "flow", "flight"};
    // vector<string> arr = {"dog", "racecar", "car"};
    // vector<string> arr = {"c","acc","ccc"}; // ans empty hai

    // printArr(arr);
    cout<<"Printing ans "<<endl;
    string ans = longestCommonPrefix(arr);

    cout<<ans<<endl;

    return 0;
}