#include <iostream>

using namespace std;

int findGCDIterative(int num1, int num2)
{
    if (num1 == 0 || num2 == 0)
        return 0;

    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
        {
            num1 = num1 - num2;
        }
        else
        {
            num2 = num2 - num1;
        }
    }

    return num1 >= 0 ? num1 : num2;
}

int main()
{
    // lcm = a*b/gcd

    int num1 = 8, num2 = 2; // 14

    // int ans = findGCD(num1, num2);
    int gcd = findGCDIterative(num1, num2);
    int lcm = (num1 * num2 )/ gcd;

    cout << "LCM of " << num1 << " and " << num2 << " is " << lcm << endl;

    return 0;
}