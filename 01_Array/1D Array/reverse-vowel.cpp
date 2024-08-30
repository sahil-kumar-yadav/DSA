#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return true;

    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return true;

    return false;
}

void reverseVovel(string &str)
{
    int i = 0, j = str.size() - 1;

    while (i < j)
    {
        if (isVowel(str[i]) && isVowel(str[j]))
        {
            swap(str[i], str[j]);
            i++, j--;
        }

        if (!isVowel(str[i]))
        {
            i++;
        }
        if (!isVowel(str[j]))
        {
            j--;
        }
    }
}

int main()
{
    string str = "leetcode";
    cout << "Original string ";
    cout << str << endl;
    reverseVovel(str);

    cout << "reversed string " << str << endl; // leotcede

    return 0;
}