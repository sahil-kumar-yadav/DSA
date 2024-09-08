#include <iostream>

enum Day
{
    sunday = 0,
    monday = 1,
    tuesday = 2,
    wednesday = 3,
    thursday = 4,
    friday = 5,
    saturday = 6
};

use namespace std;
int main()
{

    //  enums = a user-defined data type that consists
    //                  of paired named-integer constants.
    //                 GREAT if you have a set of potential options

    Day today = friday;

    switch (today)
    {
    case sunday:
        cout << "It is Sunday!\n";
        break;
    case monday:
        cout << "It is Monday!\n";
        break;
    case tuesday:
        cout << "It is Tuesday!\n";
        break;
    case wednesday:
        cout << "It is Wednesday!\n";
        break;
    case thursday:
        cout << "It is Thursday!\n";
        break;
    case friday:
        cout << "It is Friday!\n";
        break;
    case saturday:
        cout << "It is Saturday!\n";
        break;
    }

    return 0;
}