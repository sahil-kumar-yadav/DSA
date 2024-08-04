#include <iostream>

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

int main()
{
    string str = "abcd";
    int n = 4;
    int i = 0;
    findsubSequece(str, n, i, "");

    return 0;
}