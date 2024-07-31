#include <iostream>

using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortColorsByCount(int arr[], int n)
{
    int zeroCount = 0, oneCount = 0, twoCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            zeroCount++;
        }
        else if (arr[i] == 1)
        {
            oneCount++;
        }
        else
        {
            twoCount++;
        }
    }

    int i = 0;
    // zero in starting
    while (zeroCount--)
    {
        arr[i++] = 0;
    }
    // one in middle
    while (oneCount--)
    {
        arr[i++] = 1;
    }
    // two in last
    while (twoCount--)
    {
        arr[i++] = 2;
    }
}

void sortColorsByTwoPointer(int arr[], int n)
{

    // 2 ko last my pucha dete hai
    int s = 0, e = n - 1;
    while (s < e)
    {
        bool cond1 = (arr[e] == 2);
        bool cond2 = (arr[s] == 2);

        if (cond1)
        {
            // sahi hai
            e--;
        }
        else if (cond2)
        {
            swap(arr[s], arr[e]);
        }
        else
        {
            s++;
        }
    }


    // abh 1 or zero ko kar dete hai
    s = 0;
    while (s < e)
    {
        bool cond1 = (arr[e] == 1);
        bool cond2 = (arr[s] == 1);

        if (cond1)
        {
            // sahi hai
            e--;
        }
        else if (cond2)
        {
            swap(arr[s], arr[e]);
        }
        else
        {
            s++;
        }
    }

}

void cleanCode(int arr[], int n){
    // not working 
    int start = 0,end = n-1,i = 0;

    while(start <= end ){
        cout<<start<<" "<<i<<" "<<end<<endl;
        if(arr[i] == 0){
            swap(arr[i],arr[start]);
            i++;
            start++;
        }
        else if(arr[i] == 2){
            swap(arr[i],arr[end]);
            end--;
        }
        else{
            i++;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 0, 2, 1, 1, 0, 1, 1, 2, 1, 0, 0}; // 0->red 1->blue 2->green
    int n = 14;
    // sortColorsByCount(arr, n);
    // sortColorsByTwoPointer(arr, n);
    cleanCode(arr, n);
    printArr(arr, n);

    return 0;
}