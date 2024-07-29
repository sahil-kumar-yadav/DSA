#include<iostream>

using namespace std;

void inverted_half_pyramid(){

    for(int i = 1;i<=5;i++){
        for(int j = 5;j>=i;j--){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    inverted_half_pyramid();

    return 0;

}