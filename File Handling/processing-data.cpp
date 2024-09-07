#include <iostream>
#include <fstream>
#include<algorithm>
using namespace std;
int main()
{

    // input kar rahe honge array

    int arr[] = {4, 2, 1, 5};
    int n = 4;

    ofstream foutObj;

    foutObj.open("arryfile.txt");

    foutObj << "Original Array\n";

    for (int i = 0; i < n; i++)
    {
        foutObj << arr[i] << " "; // space dene ke liye
    }

    // sorting array
    sort(arr,arr+n);
    
    foutObj<<"\nSorted Array\n";
    
    for (int i = 0; i < n; i++)
    {
        foutObj << arr[i] << " "; // space dene ke liye
    }

    foutObj.close();
    return 0;
}