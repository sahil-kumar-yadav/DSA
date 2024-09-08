#include <iostream>
#include <string>

using namespace std;
int main()
{
    string str("Insidecode");
    // cout << str << endl;

    string::reverse_iterator r;
    for (r = str.rbegin(); r < str.rend(); r++)
    {
        cout << *r;
    }

    return 0;
}