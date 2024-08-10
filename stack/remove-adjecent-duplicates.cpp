#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(stack<char> st)
{
    cout << "Printing stack " ;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

string removeAdjecent(string str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i]; // abbaca

        cout << "ch " << ch << endl;
       
        if (st.empty())
        {
            st.push(ch);
        }
        else
        {
            if (ch == st.top())
            {
                while (ch == st.top())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(ch);
            }
        }
        printStack(st);
        
    }

    string newstr = "";

    while (!st.empty())
    {
        newstr += st.top();
        st.pop();
    }

    return newstr;
}

int main()
{
    string str = "acaaabbbacdddd";
    string ans = removeAdjecent(str);
    cout << "ans " << ans << endl;

    return 0;
}