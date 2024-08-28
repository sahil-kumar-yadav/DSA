#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{
    // leetcode 239
    vector<string> timePoints{"23:59", "00:00", "12:10"};
    int n = timePoints.size();
    int minDiff = INT_MAX;
    vector<int> timeMinutes(n, 0);
    int i = 0;
    for (auto it : timePoints)
    {
        int hours = stoi(it.substr(0, 2));
        int min = stoi(it.substr(3, 2));
        timeMinutes[i++] = hours * 60 + min;
        cout << hours << " ";
        cout << min << " " << endl;
    }
    sort(timeMinutes.begin(), timeMinutes.end());
    for (auto it : timeMinutes)
    {
        cout << it << " ";
    }

    int mini = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        int diff = abs(timeMinutes[i] - timeMinutes[i + 1]);
        if (diff >= 720)
        {
            diff = 1440 - diff;
        }
        mini = min(mini, diff);
    }
    int diff = abs(timeMinutes[0] - timeMinutes[n - 1]);
    if (diff >= 720)
    {
        diff = 1440 - diff;
    }
    mini = min(mini, diff);
    cout << "minimum time difference is " << mini << endl;

    return 0;
}