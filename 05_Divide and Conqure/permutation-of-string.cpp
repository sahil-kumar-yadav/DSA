#include<iostream>
#include<string>

using namespace std;

void printPermutation(string str,int i){
    if(i>=str.length()){
        cout<<str<<endl;
        return;
    }

    for(int j = i;j<str.length();j++){
        swap(str[i],str[j]);
        // recursive call
        printPermutation(str,i+1);
        
        // backtrack
        swap(str[i],str[j]);

    }
}

int main(){
    string str = "abc";
    printPermutation(str,0);

    return 0;

}