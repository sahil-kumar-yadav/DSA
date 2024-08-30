#include <iostream>
#include <string>

using namespace std;
// int count = 0;

bool checkPalindrome(string s)
{
    int i = 0, j = s.size();
    if (i == j)
        return true;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

// void countPalindromicSubStr(string s, string ans, int i, int n)
// {
//     if (i >= n)
//         return;

//     string exclude = ans;
//     if (checkPalindrome(exclude))
//     {
//         count++;
//         countPalindromicSubStr(s, exclude, i + 1, n);
//     }

//     string include = ans + s[i];
//     if (checkPalindrome(include))
//     {
//         count++;
//         countPalindromicSubStr(s, include, i + 1, n);
//     }
// }


int expandAroundIndex(string s, int i, int j)
{
    int cnt = 0;

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        cnt++;
        i++, j--;
    }
    return cnt;
}

int countSubstring(string &s)
{
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        // odd
        int oddKaAns = expandAroundIndex(s, i, i);
        count += oddKaAns;

        // even
        int evenAns = expandAroundIndex(s, i, i + 1);
        count += oddKaAns;
    }

    return count;
}

int main()
{
    // leetcode 647
    string s = "aaa";
    int n = s.length();
    // countPalindromicSubStr(s, "", 0, n); / not giving correct ans;

    int count = 0;
    // here we will use concept of odd substring and even substring

    count = countSubstring(s);

    cout << "count is " << count << endl;

    return 0;
}