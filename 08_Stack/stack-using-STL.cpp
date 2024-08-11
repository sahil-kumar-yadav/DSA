#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<int>s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    cout<<"top "<<s.top()<<endl;
    cout<<"size "<<s.size()<<endl;
    s.pop();
    cout<<"top "<<s.top()<<endl;
    cout<<"size "<<s.size()<<endl;

    cout<<"empty check "<<s.empty()<<endl;

    return 0;

}