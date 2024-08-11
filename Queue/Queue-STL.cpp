#include<iostream>
#include<queue>

using namespace std;
int main(){
    queue<int>q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    cout<<"size of q is "<<q.size()<<endl;
    cout<<"front of q is "<<q.front()<<endl;
    cout<<"rear of q is "<<q.back()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    return 0;

}