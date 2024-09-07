#include<iostream>
#include<fstream>

using namespace std;
int main(){

    // file me hum jo bhi kaam karte hai vo object ke through karte hai
    // cout, cin be ek object hai
    
    // so hum file handling ke liye 4 step follow karte hai
    // step 1 : create object from fstram file
    // step 2 : open a file or it will create a new file
    // step 3 : do processing , reading or writing 
    // step 4 : close the file


    ofstream foutObj; // step1 

    foutObj.open("sample.txt"); // step 2 created a new file
    
    // step 3
    foutObj<<"This is a sample text for this file written by sahil yadav"; // write kar diya

    // step 4
    foutObj.close(); // release the resources of ram

    return 0;

}