#include <iostream>
#include <string>

using namespace std;
bool checkValid(string s, string t)
{

    // agar dono ki size he alag hai to false return kardo

    if (s.length() != t.length())
        return false;
    // cout<<"ds";
    // m-1 count frequency in s and t compare

    int sfreq[27] = {0};
    int tfreq[27] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        sfreq[s[i] - 'a']++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        tfreq[t[i] - 'a']++;
    }
    cout<<"Printing "<<endl;
    for (int i = 0; i < 27; i++)
    {
        cout<<sfreq[i]<<" ";
        if (sfreq[i] != tfreq[i])
            return false;
    }

    return true;
}
int main()
{
    // string s = "anagram";
    // string t = "nagaram";
    string s = "nl";
    string t = "cx";

    bool isValid = checkValid(s, t);

    if (isValid)
    {
        cout << "Valid anangram " << endl;
    }
    else
    {
        cout << "Invalid anagram" << endl;
    }

    return 0;
}