#include<iostream>

using namespace std;

void peakElement(int arr[],int n){

    int ans = -1;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;
    // agar increasing hai to left side my hoga else
    // agar mid decreasing order my hai to right my hoga
    while (start <= end)
    {
        // cout << "start " << start << " mid " << mid << " end " << end << endl;
         // agar increasing hai to left side my hoga else
        // agar mid decreasing order my hai to right my hoga
        if (arr[mid] > arr[mid-1] &&  arr[mid] > arr[mid+1] )
        {
            // found peak element
            ans = arr[mid];
            break;
        }
        else if (arr[mid] > arr[mid-1])
        {
            // increasing order my hai
            start = mid + 1;
        }
        else
        {
            // arr[mid] > target
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    // return false;
    cout << "printing ans " << endl;
    cout<<ans<<endl;
}

int main(){
    int arr[] = {0,10,5,2};
    int n = 4;
    peakElement(arr,n);

    return 0;

}