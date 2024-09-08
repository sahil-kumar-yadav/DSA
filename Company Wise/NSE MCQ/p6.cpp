#include <iostream>
enum seasons
{
    spring,
    summer,
    autumn,
    winter
};

using namespace std;
int main()
{
    seasons s;

    s = spring;
    cout << "spring = " << s << endl;
    s = spring;
    cout << "summer = " << s << endl;
    s = spring;
    cout << "autumn = " << s << endl;
    s = spring;
    cout << "winter = " << s << endl;

    return 0;
}