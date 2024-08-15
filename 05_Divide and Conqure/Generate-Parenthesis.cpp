#include<iostream>
#include<vector>
#include<string>

using namespace std;

void generateParenthesis(vector<string> &ans,int open,int close,string currStr){
    if(open < 0 || close < 0){
        return;
    }

    if(open == 0 && close == 0){
        ans.push_back(currStr);
        return;
    }

    // open ko include karo
    generateParenthesis(ans,open-1,close,currStr+"(");

    // close ko include karo only if open already exists
    bool condition = open < close;
    if(condition)
        generateParenthesis(ans,open,close-1,currStr+")");
    
}


int main(){
    int n = 2;
    vector<string> ans;

    generateParenthesis(ans,n,n,"");

    cout<<"Printing ans "<<endl;
    for(auto it:ans){
        cout<<it<<" ";
    }

    return 0;

}