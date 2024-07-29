#include <iostream>

using namespace std;

void half_pyramid()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

int main()
{

    half_pyramid();
    return 0;
}