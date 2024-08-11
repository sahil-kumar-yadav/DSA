#include <iostream>
#include <stack>

using namespace std;

void findNextGreater(int arr[], int n, int nextArr[])
{
    // {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    stack<int> st;
    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            if (!st.empty())
                nextArr[i] = st.top();
        }
        st.push(arr[i % n]);
    }

    cout << "Printing next Greater element array " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << nextArr[i] << " ";
    }
}

int main()
{
    // int arr[] = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    int arr[] = {7, 8, 1, 4};
    int n = 4;
    int nextArr[n] = {0};

    findNextGreater(arr, n, nextArr);

    return 0;
}