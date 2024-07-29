#include<iostream>

using namespace std;

void full_pyramid(){
    for(int i = 1;i<=5;i++){
        for(int j = 5;j>=i;j--){
            cout<<"  ";
        }
        for(int j = 1;j<= 2*i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
int main(){
    full_pyramid();

    return 0;

}