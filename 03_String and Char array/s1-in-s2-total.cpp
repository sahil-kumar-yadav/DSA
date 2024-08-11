#include <iostream>
#include <string>
#include<vector>

using namespace std;

int count = 0;
vector<string>ans;
void getSubsequenceCount(string &s1, string &s2, int &strlen, int i, string output, string index)
{
    if (i >= strlen)
    {
        return;
    }

    if (output == s1)
    {
        // ans.push_back(output);
        ans.push_back(index);
        count++;
    }

    cout<<output<<endl;

    // include
    string include = output + s2[i];
    getSubsequenceCount(s1, s2, strlen, i + 1,include , index + to_string(i) );

    // exclude
    getSubsequenceCount(s1, s2, strlen, i + 1, output, index);
}

int main()
{
    string s1 = "ABC";
    string s2 = "ABCBABC";
    int i = 0;
    int strlen = s2.length();
    // cout<<strlen<<" jj";

    getSubsequenceCount(s1, s2, strlen, i, "", "");

    cout << "count is " << count << endl;

    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;
}