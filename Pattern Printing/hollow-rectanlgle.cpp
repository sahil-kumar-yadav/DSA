#include <iostream>

using namespace std;

void hollow_rect()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            // 1 row // last row // first col // last col
            if (i == 1 || j == 1 || i == 5  || j == 5)
            {
                cout << "* ";
            }
            else{
                cout<<"  "; // print gap also
            }
        }
        cout<<endl;
    }
}

int main()
{
    hollow_rect();

    return 0;
}