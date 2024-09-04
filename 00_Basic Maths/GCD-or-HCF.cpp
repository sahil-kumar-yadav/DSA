#include <iostream>

using namespace std;

int findGCD(int num1, int num2)
{
    // Euclidean algorithm by subtraction
    // better optimized solution exist
    if (num1 <= 0)
    {
        return num2;
    }
    if (num2 <= 0)
    {
        return num1;
    }

    if (num1 > num2)
    {
        return findGCD(num1 - num2, num2);
    }

    return findGCD(num1, num2 - num1);
}

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
    // int num1 = 24, num2 = 72; // 24
    int num1 = 98, num2 = 56; // 14

    // int ans = findGCD(num1, num2);
    int ans = findGCDIterative(num1, num2);

    cout << "GCD of " << num1 << " and " << num2 << " is " << ans << endl;

    return 0;
}