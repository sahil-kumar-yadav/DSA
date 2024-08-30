#include <iostream>
#include <string>

using namespace std;

int expandAroundIndex(string s, int i, int j)
{
    int cnt = 0;
    // increase count untill matching

    while (i >= 0 && j < s.length() && s[i] == s[j])
    {
        cnt++;
        i--;
        j++;
    }
    return cnt;
}
int countSubstring(string s)
{
    int count = 0;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        // odd
        int oddkaAns = expandAroundIndex(s, i, i);
        count = count + oddkaAns;
        // evev
        int evevkaAns = expandAroundIndex(s, i, i + 1);
        count = count + evevkaAns;
    }

    return count;
}

int main()
{
    // string s= "abc"; // a b c
    // string s= "abaab";
    // string s= "aaa"; // a aa aaa
    string s = "noon"; // n o n oo noon
    int ans = countSubstring(s);

    cout << "ans is " << ans;
    return 0;
}