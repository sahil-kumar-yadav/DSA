#include <iostream>

using namespace std;

double myPowBruteForce(double &x, int &n)
{
    long double ans = 1;
    long double val = x;
    if (n > 0)
    {
        while (n--)
        {
            ans *= val;
        }
    }
    else
    {
        while (n < 0)
        {
            ans /= val;
            n++;
        }
    }

    return ans;
}

double myPowBOptimized(double &x, int &n)
{
    long long int pow = n;
    double ans = 1.0;
    if(pow<0)
        pow =  -1*pow;
    while (pow > 0)
    {
        if (pow % 2 == 1)
        {
            // if power is even
            ans = ans * x;
            pow = pow - 1;
        }
        else
        {
            // pow even 2 4 6 8
            x = x * x;
            pow = pow / 2;
        }
    }
    if(n<0)
        ans =  1.0/ans;
    return ans;
}

int main()
{
    
    // double val = 4;
    // int power = 8;
    // double ans = myPowBruteForce(val, power);
    // cout << ans << endl;
    double val = 4;
    int power = 8;
    double ans2 = myPowBOptimized(val, power);
    cout << ans2 << endl;

    return 0;
}