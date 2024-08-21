#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str = "abcde";

    int count = 3;

    for (int i = str.length() - 1; i >= 0; i--)
    {
        char ch = str[i];

        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')
        {
            count--;
        }

        if (count == 0)
        {
            cout << str[i] << endl;
            break;
        }
    }

    return 0;
}