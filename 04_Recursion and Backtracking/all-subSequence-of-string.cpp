#include <iostream>
#include <vector>

using namespace std;

void findsubSequece(string str, int n, int i, string ans)
{
    if (i >= n)
    {
        if (ans != "")
        {

            cout << ans << endl;
        }
        return;
    }

    // exclude
    findsubSequece(str, n, i + 1, ans);

    // include
    string included = ans + str[i];

    findsubSequece(str, n, i + 1, included);
}

void newapproch(string str)
{

    int n = str.length();
    // cout<<n;
    // let say 2 hai
    // to 2 ke saare combination banege
    // 0 0
    // 0 1
    // 1 0
    // 1 1

    vector<vector<int>> allBinaryCombination{{0, 0,0}, {0, 1}, {1, 0}, {1, 1}};

    // findallCombination(allBinaryCombination);

    // manlo aa gye

    // abh saare combination ki string generate karni hai

    for (auto it : allBinaryCombination)
    {
        string ans = "";
        for (int i = 0; i < it.size(); i++)
        {
            if (it[i] == 0)
            {
                continue;
            }
            else
            {
                ans += str[i];
            }
        }
        cout << ans << endl;
    }
}

int main()
{
    // string str = "abcdef";
    string str = "ab";
    int n = str.length();
    int i = 0;
    // findsubSequece(str, n, i, "");
    newapproch(str);

    return 0;
}