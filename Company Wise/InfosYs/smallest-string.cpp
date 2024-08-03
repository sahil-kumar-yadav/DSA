#include <iostream>
#include <string>

using namespace std;

void smallestString(string &str)
{
    string st = "10";

    while (str.find(st) != string::npos)
    {
        int pos = str.find(st);
        int len = str.length();
        string newStr1 = str.substr(0, pos);
        string newStr2 = str.substr(pos + 1, len - 1);
        cout << newStr1 <<"     ";
        cout << newStr2 << endl;
        str = newStr1 + newStr2;
    }
    cout<<"print"<<endl;
    cout<<str<<endl;
}
int main()
{
    string str = "1101111"; // 0001
    // string text = "Apple, Banana, Kiwi";
    // string st = "10";
    // int pos = str.find(st);
    // int len = str.length();
    // string newStr1 = str.substr(0, pos);
    // string newStr2 = str.substr(pos + 1, len - 1);
    // cout << newStr1 << endl;
    // cout << newStr2 << endl;

    smallestString(str);

    return 0;
}