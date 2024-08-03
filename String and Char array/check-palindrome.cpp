#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str)
{

    int i = 0, j = str.length()-1;
    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

int main()
{

    // string str = "noon";
    // string str = "kadak";
    string str = "sahil";
    bool ans = checkPalindrome(str);

    if (ans)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not a Palindorme" << endl;
    }

    return 0;
}