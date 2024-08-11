#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int main(){
    
    char str[100];
    cin.getline(str,100);
    cout<<str<<endl;
    
    for(int i = 0;i<strlen(str);i++){
        if(str[i] == ' '){
            str[i] = '@';
        }
    }
    
    cout<<str;


    return 0;

}