#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX and INT_MIN

using namespace std;

// Global variable to define the size of the array
const int n = 10;

// Define a struct to store both min and max
struct MinMax
{
    int min;
    int max;
};

// Segment tree vector with size 4 times the array size
vector<MinMax> segmentTree(4 * n, {INT_MAX, INT_MIN});

// Function to build the segment tree
void buildSegmentTree(const int arr[], int index, int start, int end)
{
    if (start == end)
    {
        // Leaf node in the segment tree
        segmentTree[index] = {arr[start], arr[start]};
        return;
    }

    int mid = (start + end) / 2;

    // Recursively build the left and right subtrees
    buildSegmentTree(arr, 2 * index + 1, start, mid);
    buildSegmentTree(arr, 2 * index + 2, mid + 1, end);

    // Internal node will have the min and max of its children
    segmentTree[index].min = min(segmentTree[2 * index + 1].min, segmentTree[2 * index + 2].min);
    segmentTree[index].max = max(segmentTree[2 * index + 1].max, segmentTree[2 * index + 2].max);
}

// Function to find the min and max values in a given range [queryStart, queryEnd]
MinMax findMinMaxUsingSegmentTree(int index, int segmentStart, int segmentEnd, int queryStart, int queryEnd)
{
    // No overlap
    if (segmentEnd < queryStart || segmentStart > queryEnd)
    {
        return {INT_MAX, INT_MIN}; // Return extreme values representing no overlap
    }

    // Complete overlap
    if (segmentStart >= queryStart && segmentEnd <= queryEnd)
    {
        return segmentTree[index];
    }

    // Partial overlap
    int mid = (segmentStart + segmentEnd) / 2;
    MinMax leftResult = findMinMaxUsingSegmentTree(2 * index + 1, segmentStart, mid, queryStart, queryEnd);
    MinMax rightResult = findMinMaxUsingSegmentTree(2 * index + 2, mid + 1, segmentEnd, queryStart, queryEnd);

    // Combine results from left and right children
    return {min(leftResult.min, rightResult.min), max(leftResult.max, rightResult.max)};
}

int main()
{
    // Example array and range queries
    int arr[] = {1, 8, 5, 9, 6, 14, 2, 4, 3, 7};
    vector<pair<int, int>> queries = {
        {0, 4},
        {3, 7},
        {1, 6},
        {2, 5},
        {0, 8}};

    // Build the segment tree
    buildSegmentTree(arr, 0, 0, n - 1);

    // Print the segment tree
    // cout << "Segment tree (min, max):" << endl;
    // for (const auto &node : segmentTree)
    // {
    //     cout << "(" << node.min << ", " << node.max << ") ";
    // }
    // cout << endl;

    // Process each query
    cout << "Query results (min max):" << endl;
    for (const auto &query : queries)
    {
        int queryStart = query.first;
        int queryEnd = query.second;
        MinMax result = findMinMaxUsingSegmentTree(0, 0, n - 1, queryStart, queryEnd);
        cout << "Range [" << queryStart << ", " << queryEnd << "] -> Min: " << result.min << ", Max: " << result.max << endl;
    }

    return 0;
}
