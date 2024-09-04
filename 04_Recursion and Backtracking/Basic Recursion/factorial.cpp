#include<iostream>

using namespace std;

int fact(int n){
    if(n==1) return 1;
    int ans = n*fact(n-1);
    return ans;
}

int main(){
    int n = 5;
    int ans = fact(n);
    cout<<"ans "<<ans<<endl;

    return 0;

}