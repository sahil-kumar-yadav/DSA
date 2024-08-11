#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool checkOpening(char ch)
{
    return (ch == '(') || (ch == '[') || (ch == '{');
}

bool checkSameClosing(char a, char b)
{
    bool cond1 = (a == '(' && b == ')');
    bool cond2 = (a == '{' && b == '}');
    bool cond3 = (a == '[' && b == ']');
    return  (cond1 || cond2 || cond3 );
}

bool isValid(string str)
{
    if (str.empty())
        return true;
    stack<char> s;

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        // cout<<"ch = "<<ch<<" "<<endl;
        if (checkOpening(ch))
        {
            s.push(ch);
        }
        else
        {
            // closing hoga
            if (s.empty())
            {
                // closing bracket for no previous opening
                return false;
            }
            char top = s.top();
            if (checkSameClosing(top, ch))
            {
                s.pop();
            }
            else
            {
                // opening bracket is not same as closing
                // { } ( "]" ( ){}{{(())}}
                return false;
            }
        }
    }

    if (!s.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    // string str = "(){}[]";
    // string str = "(){[]()}";
    // string str = "(){[])";
    string str = "(){[]}]";

    bool checkValid = isValid(str);

    if (checkValid)
    {
        cout << "parenthisis is valid " << endl;
    }
    else
    {
        cout << "parenthisis is not valid" << endl;
    }

    return 0;
}