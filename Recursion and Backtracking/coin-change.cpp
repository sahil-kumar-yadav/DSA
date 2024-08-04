#include <iostream>
#include <vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

void countWays(int arr[], int n, int target, int &ways, set<string> &store, string output)
{
    if (target < 0)
        return;

    if (target == 0)
    {
        sort(output.begin(),output.end());
        store.insert(output);
        ways++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        output += to_string(arr[i]);
        countWays(arr, n, target - arr[i], ways,store,output);
        output.pop_back();
        
    }
}

int main()
{
    int arr[] = {1, 2, 3};
    int n = 3;

    int target = 5; // 11111 ; 2,3 ; 1112;113;221;
    int ways = 0;
    set<string> ans;
    
    countWays(arr, n, target, ways, ans, "");
    cout << "ways " << ways << endl;
    cout<<"printing "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}