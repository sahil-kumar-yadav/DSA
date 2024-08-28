#include <iostream>
#include <string>

using namespace std;

void removeAlloccurance(string &str, string &substr)
{

    int pos = str.find(substr);
    int length = substr.length();
    while (pos != string::npos)
    {
        str.erase(pos, length);
        pos = str.find(substr);
    }
}
int main()
{
    // string str = "daabcbaabcbc"; // dab 
    // string substr = "abc"; 
    string str = "axxxxyyyyb"; // ab 
    string substr = "xy";
    removeAlloccurance(str, substr);

    cout << str << endl;

    return 0;
}