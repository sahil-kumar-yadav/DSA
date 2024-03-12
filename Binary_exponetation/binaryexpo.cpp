#include<iostream>

using namespace std;

int power(int a,int b){

    if(b == 0)
        return 1;

    if(b == 1)
        return a;

    int smallans = power(a,b/2);
    // this wont work fine for odd power so we have to add one extra codition
    
    int result = (smallans*smallans);
    if((b%2) == 1){
        // power is odd 
        result = result*a;
    }

    return result;

}

int poweriterative(int a,int b){
    int result = 1;

    while(b>0){

        // b ko  half karna hai

        // result = a^b/2*a^b/2;
        if(b%2 == 1){
            result = result*a;
        }
        a = a*a;

        b = b/2;

    }
    return result;
}
int main(){
    int a = 2,b = 5;
    // a^b calculate karna hai
    int ans = power(a,b);
    int ans1 = poweriterative(a,b);
    cout<<a<<" power "<<b<<" is "<<ans<<endl;
    cout<<a<<" power "<<b<<" is "<<ans1<<endl;
    return 0;
}