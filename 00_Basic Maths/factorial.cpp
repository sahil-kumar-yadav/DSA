#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void fact(int n)
{
    vector<int> ans;
    long long int sum = 0, carry = 0;
    ans.push_back(1);

    for (int i = 2; i <= n; i++)
    {
        sum = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            sum = (ans[j] * i) + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans[j] = sum;
        }

        while (carry)
        {
            ans.push_back(carry % 10);
            carry = carry / 10;
        }
    }

    reverse(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
    }
}
int main()
{

    return 0;
}