#include <iostream>

using namespace std;
void printNumbersReverse(int n)
{
    if (n == 0)
        return;
    printNumbersReverse(n - 1);
    cout << n << " ";
}
void printNumbers(int n, int i)
{
    if (i == n+1)
        return;
    cout << i << " ";
    printNumbers(n, i + 1);
}
int main()
{
    int n = 5;
    printNumbers(n, 1);

    return 0;
}