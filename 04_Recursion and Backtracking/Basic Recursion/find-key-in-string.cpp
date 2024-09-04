#include <iostream>
#include <string>

using namespace std;

bool check(string &str, char &target, int i)
{
    // base case

    if (i >= str.length())
        return false;

    // ek case humne solve kiya
    if (str[i] == target)
        return true;

    // baki ka hume nahi pata recursion sy pata karlo
    return check(str, target, i + 1);
}

int main()
{
    string str = "ABCDEF";
    char target = 'D'; // check is present or not

    bool ans = check(str, target, 0);

    if (ans)
    {
        cout << "target is present " << endl;
    }
    else
    {
        cout << "target is not present" << endl;
    }

    return 0;
}