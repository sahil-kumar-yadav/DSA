#include <iostream>
#include <string>
#include <stack>

using namespace std;

int countLongest(string str)
{
    stack<char> st;
    int count = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '(')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                    count++;
                }
            }
        }
    }

    return count;
}

int main()
{
    // string str = ")()()(())";
    string str = "())))))";

    int ans = countLongest(str);
    cout<<"ans "<<ans<<endl;

    return 0;
}