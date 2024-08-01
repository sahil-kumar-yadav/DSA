#include <iostream>
#include<string>

using namespace std;

void addTwo(int a[], int na, int b[], int nb)
{
    int nc = max(na,nb)+3;
    int ans[nc] = {0};
    int i = na - 1, j = nb - 1, k = nc - 1;
    int carry = 0;
    string ansStr = "";

    while (i >= 0 && j >= 0)
    {
        int digit1 = a[i];
        int digit2 = b[j];
        cout<<"digit1 "<<digit1<<" digit2 "<<digit2; 
        int sum = digit1 + digit2 + carry;
        int ansDigit = sum % 10;
        cout<<" ansDigit "<<ansDigit;
        ans[k] = ansDigit;
        carry = sum / 10;
        cout<<" sum "<<sum<<" carry "<<carry<<endl;
        i--;
        j--;
        k--;
    }
    cout<<" extra"<<endl;
    cout<<"i "<<i<<" j "<<j<<endl;
    while (i>=0)
    {
        int digit1 = a[i];
        cout<<"digit1 "<<digit1; 
        int sum = digit1 + carry;
        int ansDigit = sum % 10;
        cout<<" ansDigit "<<ansDigit;
        cout<<" sum "<<sum<<" carry "<<carry<<endl;
        ans[k] = ansDigit;
        carry = sum / 10;
        i--;
        k--;
    }

    while (j>=0)
    {
        cout<<" j "<<j<<endl;
        int digit2 = b[j];
        cout<<"digit2 "<<digit2; 
        int sum = digit2 + carry;
        int ansDigit = sum % 10;
        cout<<" ansDigit "<<ansDigit;
        cout<<" sum "<<sum<<" carry "<<carry<<endl;
        ans[k] = ansDigit;
        carry = sum / 10;
        j--;
        k--;
    }
    if(carry){
        ans[k] = carry;
    }

    for (int i = 0; i < nc; i++)
    {
        cout << ans[i];
    }
    int index = 0;
    while(ans[index] == 0) index++;

    while(index<nc){
        ansStr += to_string(ans[index]);
        index++;
    }
    cout<<endl;
    cout<<ansStr<<endl;
}

int main()
{
    int a[] = {3,2,6,7};
    int b[] = {9,3,0,4};
    int na = 4;
    int nb = 4;
    addTwo(a, na, b, nb);
    return 0;
}