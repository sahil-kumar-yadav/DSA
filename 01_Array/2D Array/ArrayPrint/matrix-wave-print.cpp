#include <iostream>

using namespace std;

void printArr(int arr[3][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void wavePrint(int arr[3][4],int n,int m){
    int i = 0,j = 0;

    while(j<m){
        if(j&1){
            // j odd 
            i = n-1;
            while(i>=0){
                cout<<arr[i][j]<<" ";
                i--;
            }
        }
        else{
            // j is even 0 2 4
            i = 0;
            while(i<n){
                cout<<arr[i][j]<<" ";
                i++;
            }
        }
        cout<<endl;
        j++;

    }
}

int main()
{
    int arr[3][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12}};
    int n = 3, m = 4;
    printArr(arr, n, m);
    cout<<endl;
    wavePrint(arr,n,m);

    return 0;
}