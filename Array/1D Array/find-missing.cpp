#include<iostream>

using namespace std;

void findMissingByXOR(int arr[],int n){
    int ans = 0;
    for(int i = 0;i<n;i++){
        ans ^= arr[i];
    }
    cout<<ans;
    for(int i = 1;i<n;i++){
        ans ^= i;
    }
    cout<<ans;
}

int main(){
    int arr[] = {1,3,5,3,4};
    int n = 5;

    findMissingByXOR(arr,n);

    return 0;

}