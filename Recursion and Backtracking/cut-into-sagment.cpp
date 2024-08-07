#include <iostream>

using namespace std;

int solve(int Length, int x, int y, int z)
{

    if (Length < 0)
        return INT_MIN;

    if (Length == 0)
        return 0;

    // cout<<"Length "<<Length<<endl;
    // cout<<"segmentX "<< Length - x<<endl;
    // cout<<"segmentY "<< Length - y<<endl;
    // cout<<"segmentZ "<< Length - z<<endl;

    // cout<<"X call"<<endl;
    int segmentX = Length - x >= 0 ? solve(Length - x, x, y, z) : INT_MIN;
    // cout<<"Y call"<<endl;

    int segmentY = Length - y >= 0 ? solve(Length - y, x, y, z) : INT_MIN;
    // cout<<"Z call"<<endl;
    int segmentZ = Length - z >= 0 ? solve(Length - z, x, y, z) : INT_MIN;

    

    int ans = max(segmentX, max(segmentY, segmentZ)) + 1;
    return ans;
}
int main()
{
    // int Length = 100;
    // int x = 23, y = 15, z = 50; // ans = 2
    int Length = 4;
    int x = 5, y = 3, z = 3; // ans = 2

    int ans = solve(Length, x, y, z);

    cout << ans << " sds";

    return 0;
}