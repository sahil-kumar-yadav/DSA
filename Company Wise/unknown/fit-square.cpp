#include <iostream>
#include <vector>

using namespace std;

long minArea(vector<int> &X, vector<int> &Y, int k)
{
    // code

    int intialX = 0,intialY = 0;
    int n = X.size();
    for(int i = 0;i<n;i++){
        int xnew =   X[i];
        int ynew =   Y[i];

        // check karna hai kitne point fit baith rahe hai

        // prana x 


    }
}
int main()
{
    // function should return minimum area
    // x - x coordinate
    // Y - y coordinate
    // k - minimum number of points to surround
    // constraints 10^9

    int n = 3 vector<int> X = {1, 1, 2};
    vector<int> Y = {1, 2, 1};
    int k = 3;
    long ans = minArea(X, Y, k);

    cout << "ans is " << ans << endl;

    return 0;
}