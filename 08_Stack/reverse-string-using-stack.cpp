#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main(){
    string str = "abcd";
    stack<char>s;

    for(int i = 0;i<str.length();i++){
        // char ch = str[i];
        s.push(str[i]);
    }

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }

    



    return 0;

}