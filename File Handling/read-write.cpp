#include<iostream>
#include<fstream>

using namespace std;
int main(){
    
    ofstream fout;
    fout.open("read_write.txt");
    fout<<"This is the first line";
    fout<<"\nThis is the Second line";
    fout<<"\nThis is the Third line";

    fout.close();

    ifstream fin;
    fin.open("read_write.txt");

    string line;
    // getline ek baar me puri line le leta hai
    getline(fin,line);
    cout<<line<<endl;
    while(getline(fin,line)){
        cout<<line;
        cout<<endl;
    }

    fin.close();


    return 0;

}