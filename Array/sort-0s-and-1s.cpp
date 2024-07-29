#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
    for(int i = 0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout<<endl;
}

void sortZeroAndOne(int arr[], int n)
{
    int i = 0, j = n - 1;

    while (i < j)
    {
        // cout<<i<<" "<<j<<endl;
        bool cond1 = (arr[i] == 0);
        bool cond2 = (arr[j] == 1);
        if (cond1)
        { // sahi jagh py hai
            i++;
        }
        if(cond2){
            j--;
        }
        
        if(!cond1 && !cond2){
            cout<<" cond"<<endl;
            swap(arr[i],arr[j]);
        }
    }

    
}


int main()
{
    int arr[] = {0, 1, 1, 0, 0, 1, 0, 1, 0, 1};
    int n = 10;
    sortZeroAndOne(arr,n);
    printArr(arr,n);
    return 0;
}