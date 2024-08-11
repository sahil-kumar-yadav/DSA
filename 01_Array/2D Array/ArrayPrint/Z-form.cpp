#include <iostream>

using namespace std;

void printArr(int arr[4][4], int n, int m)
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

void ZFormPrint(int arr[4][4], int n, int m)
{
    int i = 0, j = m - 1;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(i == 0 || i == n-1 || i+j == m-1){
                cout<<arr[i][j]<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }

}



int main()
{
    int arr[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};


    
    int n = 4, m = 4;
    printArr(arr, n, m);
    cout << endl;
    ZFormPrint(arr, n, m);

    return 0;
}