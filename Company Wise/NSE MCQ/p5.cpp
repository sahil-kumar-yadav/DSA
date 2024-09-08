#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream outfile("sample.txt");

    for (int n = 0; n < 5; n++)
    {
        outfile << n;
        outfile.flush();
    }
    cout << endl<< "Done";
    outfile.close();
    return 0;
}