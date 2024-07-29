#include <iostream>

using namespace std;

void solid_rectangle()
{
    for(int i = 0;i<4;i++){
        for(int j = 0;j<4;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main()
{
    solid_rectangle();

    return 0;
}