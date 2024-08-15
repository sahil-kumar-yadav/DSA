#include<iostream>

using namespace std;

void printarr(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void findNextPermutationBruteForce(int arr[],int n,int i){
    if(i >= n){
        printarr(arr,n);
        return;
    }
    //  NO swap
    // recusive call
    findNextPermutationBruteForce(arr,n,i+1);

    // swap
    swap(arr[0],arr[i]);
    // recusive call
    findNextPermutationBruteForce(arr,n,i+1);
   
}

void findNextPermutation(int arr[],int n)
{
    // find  greater index // 1 3 5 4 2
    int greaterIndex = 0;
    for(int i = n-1;i>=1;i--){
        if(arr[i-1] < arr[i]){
            greaterIndex = i-1;
            break;
        }
    }
    cout<<"greater index "<<greaterIndex<<endl;

    // find index of element greater then greaterindex
    int nextGreaterIndex = 0;

    for(int i = 0;i<n;i++){
        if(arr[i] > arr[greaterIndex]){
            nextGreaterIndex = i;
            break;
        }
    }
    cout<<"next greater index "<<nextGreaterIndex<<endl;
    // swap
    swap(arr[greaterIndex],arr[nextGreaterIndex]);

    // reverse 
    int i = greaterIndex+1,j = n-1;

    while(i<j){
        swap(arr[i],arr[j]);
        i++,j--;
    }
}
int main(){
    int arr[] = {1,2,3};
    int n = 3;

    // findNextPermutationBruteForce(arr,n,0);
    findNextPermutation(arr,n);
    printarr(arr,n);

    return 0;

}