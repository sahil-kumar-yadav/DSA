#include <iostream>

using namespace std;


int main()
{
    double esp = 1e-6;
    double x = 121;
    double lo = 0, hi = x, mid;

    while (hi - lo > esp) // to get precision till esp decimal
    {
        mid = (hi + lo)/2;
        if(mid * mid < x){
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

