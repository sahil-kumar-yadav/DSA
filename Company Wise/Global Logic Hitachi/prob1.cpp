#include<iostream>
#include<algorithm>

/* You are given an array A having N integers which represents the assembly line.
Each integer represents the height of a student.
print the indexes of all the students who stand at wrong position in the line.
11 8 4 26 7 9 2 16 1 ------denotes array A

output:0 1 3 4 6 8
*/

using namespace std;

void printarr(int arr[],int n){
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[] = {11,8,4,26,7,9,2,16,1};
            //  {1,2,,4,7,8,9,11,16,26};
    int n = 9;
    int newarr[n];
    copy(arr,arr+n,newarr);
    sort(newarr,newarr+n);
    printarr(arr,n);
    printarr(newarr,n);

    cout<<"wrong order"<<endl;
    for(int i = 0;i<n;i++){
        if(arr[i] != newarr[i]){
            cout<<i<<" ";
        }
    }
    

    return 0;

}