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

void findDuplicate_ByNegativeMarking(int arr[], int n)
{
    // vector<int>ans;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int index = abs(arr[i]) - 1; // -1 bcuz [1,n] // kyuki ho skta kisi
                                         // ny isko -ve kar diya hoga
            if (arr[index] < 0) {
                // phele he kisi ny mark kar diya
                cout << abs(index + 1) << " is a duplicate" << endl;
                // ans.push_back(index+1);
            } else {
                arr[index] = -arr[index];
            }
        }

        // if(ans.empty()){
        //     cout<<"No duplicates"
        //     // return {};
        // }

        // return ans;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    // int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    // int arr[] = {1, 3, 4, 2, 2};
    int n = 5;

    findDuplicate_ByNegativeMarking(arr, n);

    return 0;
}