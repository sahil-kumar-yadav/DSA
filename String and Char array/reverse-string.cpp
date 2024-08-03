#include <iostream>
#include <string>

using namespace std;

void reverse(string &str)
{
    int i = 0, j = str.length() - 1;
    cout << "orginal " << str << endl;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
    cout << "reversed " << str << endl;
}

int main()
{

    string str = "hello";
    reverse(str);

    return 0;
}