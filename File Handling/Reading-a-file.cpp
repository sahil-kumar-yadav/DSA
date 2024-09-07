#include <iostream>
#include <fstream>

using namespace std;
int main()
{

    // file me hum jo bhi kaam karte hai vo object ke through karte hai
    // cout, cin be ek object hai

    // so hum file handling ke liye 4 step follow karte hai
    // step 1 : create object from ifstram or ofstream file
    // step 2 : open a file or it will create a new file
    // step 3 : do processing , reading or writing
    // step 4 : close the file

    ifstream finObj; // step 1

    finObj.open("sample.txt"); // step 2 created a new file

    // char c;
    // // step 3
    // while (!finObj.eof())
    // {
    //     finObj >> c;
    //     cout << c;
    // }
    // without space aa raha

    // string str;
    // while (!finObj.eof())
    // {
    //     finObj >> str;
    //     cout << str;
    // } // yeh bhi kaam nahi karega

    char c;
    // step 3
    while (!finObj.eof())
    {
        c = finObj.get();
        cout << c;
    }

    // step 4
    finObj.close();

    return 0;
}