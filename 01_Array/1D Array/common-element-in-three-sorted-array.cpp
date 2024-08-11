#include <iostream>

using namespace std;

vector<int> commonElement(int a[], int b[], int c[], int na, int nb, int nc)
{
    vector<int> ans;
    int i = 0;
    int j = 0;
    int k = 0;

    while (i < a.size() && j < b.size() && k < c.size())
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            if (ans.empty() || ans.back() != a[i])
            {
                ans.push_back(a[i]);
            }
            i++;
            j++;
            k++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < c[k])
        {
            j++;
        }
        else
        {
            k++;
        }
    }
    return ans;

    // cout<<"completed"<<endl;
}


int main()
{
    int a[] = {1, 5, 10, 20, 40, 80};
    int b[] = {6, 7, 20, 80, 100};
    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};

    int na = 6, nb = 5, nc = 8;

    commonElement(a, b, c, na, nb, nc);

    return 0;
}