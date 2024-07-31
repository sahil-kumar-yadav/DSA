#include <iostream>
#include<unordered_map>

using namespace std;

void pair_sum_bruteforce(int a[], int na, int b[], int nb,int target)
{   
    int ans[2];

    for (int i = 0; i < na; i++)
    {
        for(int j = 0;j<nb;j++){
            if(a[i]+b[j] == target){
                ans[0] = i;
                ans[1] = j;
                break;
            }
        }
    }

    cout<<ans[0]<<" "<<ans[1];
}

void pair_sum_map(int a[], int na, int b[], int nb,int target)
{   
    int ans[2];
    unordered_map<int,int>mp;

    for(int i = 0;i<na;i++){
        mp[a[i]] = i;
    }

    for(int i = 0;i<nb;i++){
        int secondElement = target - b[i];

        if(mp.find(secondElement) != mp.end()){
            // second element found
            ans[0] = mp[secondElement];
            ans[1] = i;
            break;
        }
    }
    cout<<ans[0]<<" "<<ans[1];
}

int main()
{
    int a[] = {1, 3, 5, 7};
    int b[] = {3, 4, 6};
    int target = 9;
    // pair_sum_bruteforce(a, 4, b, 3,target);
    pair_sum_map(a, 4, b, 3,target);

    return 0;
}