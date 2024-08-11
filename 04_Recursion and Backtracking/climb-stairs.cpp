#include<iostream>

using namespace std;

int countWays(int n){
    if(n == 1 || n ==2 ){
        return 1;
    }

    int ans = countWays(n-1) + countWays(n-2);

    return ans;

}

int main(){
    
    int n = 6;

    int ans = countWays(n);
    cout<<"ans "<<ans<<endl;

    return 0;

}