#include <iostream>
#include <string>
using namespace std;

bool checkPalindrome(string str)
{

    string newStr = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            newStr += str[i];
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            newStr += str[i] + 32;
        }
        if (str[i] >= '0' && str[i] <= '9')
        {
            newStr += str[i];
        }
    }

    int i = 0, j = newStr.length() - 1;
    while (i < j)
    {
        if (newStr[i] != newStr[j])
        {
            return false;
        }
        i++, j--;
    }
    return true;
}

int main()
{

    string str = "c1 O$d@eeD o1c";
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