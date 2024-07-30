#include <iostream>
#include <vector>

using namespace std;
int main()
{
    // declaration
    vector<vector<int>> v;

    vector<vector<int>> v1{{1, 2, 3, 4},
                         {1, 2, 3, 4}};

    // intialise with some value
    vector<vector<int>> v2(10, vector<int>(10, 0)); // (size, value of row)

    return 0;
}