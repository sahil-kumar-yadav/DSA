#include<iostream>
#include<deque>

using namespace std;
int main(){
    deque<int>dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);

    cout<<"dq front is "<<dq.front()<<endl;
    cout<<"dq end is "<<dq.back()<<endl;

    dq.push_front(10);
    dq.push_front(20);
    cout<<"dq front is "<<dq.front()<<endl;
    
    dq.pop_front();
    cout<<"dq front is "<<dq.front()<<endl;

    dq.pop_back();
    cout<<"dq end is "<<dq.back()<<endl;




    return 0;

}