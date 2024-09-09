#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

long long minArea2(int x_count, int *x, int y_count, int *y, int k)
{
    // Create pairs of coordinates
    vector<pair<int, int>> p(x_count);
    for (int i = 0; i < x_count; ++i)
        p[i] = {x[i], y[i]};

    // Sort pairs based on the x coordinate
    sort(p.begin(), p.end());

    long long mn = LLONG_MAX;

    // Iterate over all possible subarrays of size k
    for (int i = 0; i <= x_count - k; ++i)
    {
        for (int j = i + k - 1; j < x_count; ++j)
        {
            // Extract y coordinates from the current subarray
            vector<int> ys;
            for (int l = i; l <= j; ++l)
                ys.push_back(p[l].second);

            // Sort y coordinates
            sort(ys.begin(), ys.end());

            // Compute the minimum area for each possible subarray of y coordinates
            for (int m = 0; m <= ys.size() - k; ++m)
            {
                int x1 = p[i].first;
                int x2 = p[j].first;
                int y1 = ys[m];
                int y2 = ys[m + k - 1];
                int sl = max(x2 - x1, y2 - y1) + 2;
                long long ar = (long long)sl * sl;
                mn = min(mn, ar);
            }
        }
    }

    return mn;
}

long minArea(int x_count, int *x, int y_count, int *y, int k)
{
    int n = x_count;
    if (k > n)
        return 0; // Edge case: if k is greater than the number of points

    // Sort the points based on x and y coordinates
    vector<pair<int, int>> points;
    for (int i = 0; i < n; ++i)
    {
        points.push_back({x[i], y[i]});
    }

    // Sort the points by their x-values first
    sort(points.begin(), points.end());

    long min_area = LONG_MAX;

    // Try each subset of points by varying the x boundaries
    for (int i = 0; i <= n - k; ++i)
    {
        for (int j = i + k - 1; j < n; ++j)
        {
            vector<int> y_subset;
            for (int l = i; l <= j; ++l)
            {
                y_subset.push_back(points[l].second);
            }

            // Sort the y-values of the current subset
            sort(y_subset.begin(), y_subset.end());

            // Try different y boundaries to find the minimum area square
            for (int m = 0; m <= y_subset.size() - k; ++m)
            {
                int side_length = max(points[j].first - points[i].first, y_subset[m + k - 1] - y_subset[m]) + 2;
                long area = static_cast<long>(side_length) * side_length;
                min_area = min(min_area, area);
            }
        }
    }

    return min_area;
}

int main()
{
    // int x_count = 2;
    // int y_count = 2;
    // int k = 2;
    // int x[] = {0, 2};
    // int y[] = {0, 4};

    // int x_count = 5;
    // int y_count = 5;
    // int k = 3;
    // int x[] = {1, 5, 3, 7, 2};
    // int y[] = {2, 6, 3, 8, 1};

    // int x_count = 4;
    // int y_count = 4;
    // int k = 2;
    // int x[] = {1, 1, 1, 1};
    // int y[] = {2, 4, 6, 8};

    // int x_count = 1;
    // int y_count = 1;
    // int k = 1;
    // int x[] = {0};
    // int y[] = {0};

    int x_count = 5;
    int y_count = 5;
    int k = 3;
    int x[] = {1, 1, 1, 1, 1};
    int y[] = {1, 1, 1, 1, 1};

    long long result1 = minArea(x_count, x, y_count, y, k);
    long long result2 = minArea2(x_count, x, y_count, y, k);

    // both are correct
    cout << "Minimum Area: " << result1 << endl;
    cout << "Minimum Area: " << result2 << endl;

    return 0;
}