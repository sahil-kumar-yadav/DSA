#include<iostream>

using namespace std;

// 0 1 1 2 3 5

int fibo(int n)
{
    if(n == 0 || n == 1){
        return n;
    }
    int ans = fibo(n-1) + fibo(n-2);
    return ans;
}

int main(){
    int n = 4;

    int ans = fibo(n);
    cout<<ans<<endl;

    return 0;

}