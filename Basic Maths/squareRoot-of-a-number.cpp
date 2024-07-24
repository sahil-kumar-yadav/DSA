#include <iostream>

using namespace std;

double multiply(double mid,int n){
    int ans = 1;
    while(n--){
        ans *= mid;
    }
    return ans;
}

int main()
{
    double esp = 1e-6;
    double x = 4;
    double lo = 0, hi = x, mid;
    int n = 2;

    while (hi - lo > esp) // to get precision till esp decimal
    {
        mid = (hi + lo)/2;
        if(multiply(mid,n) < x){
            lo = mid;
        }
        else{
            hi = mid;
        }
    }
    cout<<lo<<endl;
    cout<<hi<<endl;
    return 0;
}

