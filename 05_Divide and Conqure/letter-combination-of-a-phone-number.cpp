#include <iostream>

using namespace std;

void findsubSequece(string str, int n, int i, string ans)
{
    int len = ans.length();
    if (i > n)
    {
        return;
    }
    if (len >= 2)
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

int main()
{
    string number = "23";
    // number ko string my include kar liya
    string str = "abcdef";
    int n = 4;
    int i = 0;
    findsubSequece(str, n, i, "");

    return 0;
}