#include <iostream>

using namespace std;

void tilted_half_pyramid()
{

    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i == 1 || j == 1 || (i + j) == 5+1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

int main()
{
    tilted_half_pyramid();

    return 0;
}