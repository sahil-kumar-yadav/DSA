#include<iostream>

using namespace std;

void reverseDigits(int num){
    int reverseNum = 0;

    while(num){
        cout<<"num "<<num;
        int digit = num%10;
        cout<<" digit "<<digit<<endl;
        reverseNum = reverseNum*10 + digit;
        num = num/10;
    }
    cout<<reverseNum<<endl;
}

int main(){
    int num = 32100;
    reverseDigits(num);

    return 0;

}