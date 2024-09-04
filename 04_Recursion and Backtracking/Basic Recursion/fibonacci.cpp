#include <iostream>

using namespace std;

// 0 1 1 2 3 5

int fibo(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    int nthFibo = fibo(n - 1) + fibo(n - 2);
    return nthFibo;
}

void fiboprint(int n, int &prev, int &prevtoprev)
{
    if (n == 0)
    {
        prev = 1;
        prevtoprev = 0;
        return;
    }
    fiboprint(n - 1, prev, prevtoprev);
    cout << prevtoprev << " ";
    int curr = prev + prevtoprev;
    prevtoprev = prev;
    prev = curr;

    return;
}

int main()
{
    int n = 8;

    int ans = fibo(n);

    int prev = 0, prevtoprev = 0;
    fiboprint(n, prev, prevtoprev);
    cout << ans << endl;

    return 0;
}