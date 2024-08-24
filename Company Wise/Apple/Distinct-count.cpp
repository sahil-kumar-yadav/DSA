#include <iostream>
#include <unordered_map>
#include <stack>

using namespace std;
int main()
{
    // choose 3 triples out of which 2 should be adjecent , such that
    // a[1st]*a[2nd]*a[3rd] == desired capacity
    // int capacity[] = {1, 2, 2, 2, 4};
    // int n = 5;
    // int desiredCap = 8; // ans 3
    // eg 1*2*4 = 8
    // eg 2*2*2 = 8
    // eg 2*4*1 = 8
    int capacity[] = {1, 3, 5, 3, 5};
    int n = 5;
    int desiredCap = 15; // ans 4
    // eg 1*3*5 = 15
    // eg 3*5*1 = 15
    // eg 5*3*1 = 15
    // eg 3*5*1 = 15

    unordered_map<int, int> mp;
    // duplicate vala case handel karne ky liye
    stack<pair<int, int>> st;

    // create a mp
    for (int i = 0; i < n; i++)
    {
        mp[capacity[i]]++;
    }

    // use two pointer to go throught adjecents

    for (int i = 0; i < n - 1; i++)
    {
        cout << "i " << i << endl;
        int producttwoAdj = capacity[i] * capacity[i + 1];
        // dono ka mp sy count decrease kardo
        mp[capacity[i]]--;
        mp[capacity[i + 1]]--;
        int thirdElement = desiredCap / producttwoAdj;
        if (mp.find(thirdElement) != mp.end())
        {
            // abh find karo 3rd pair hai kya array my
            // agar 3rd element hai array me
            pair<int, int> p = {capacity[i], capacity[i + 1]};
            if (st.empty() || st.top() != p)
            {
                // prev push element jesa nahi hai
                st.push({capacity[i], capacity[i + 1]});
            }
        }

        // abh vaps increase kardo next iteration ky liye
        mp[capacity[i]]++;
        mp[capacity[i + 1]]++;
    }

    cout << "total triplets are " << st.size() << endl;

    return 0;
}