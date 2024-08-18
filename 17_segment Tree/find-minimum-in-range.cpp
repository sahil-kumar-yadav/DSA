#include <iostream>
#include <vector>
#include <limits.h> // For INT_MAX

using namespace std;

// Global variable to define the size of the array
int n = 10;

// Segment tree vector with size 4 times the array size
vector<int> segmentTree(4 * n, 0);

// Function to build the segment tree
void buildSegmentTree(int arr[], int index, int start, int end)
{
    if (start == end)
    {
        // Leaf node in the segment tree
        segmentTree[index] = arr[start];
        return;
    }

    int mid = (start + end) / 2;

    // Recursively build the left and right subtrees
    buildSegmentTree(arr, 2 * index + 1, start, mid);
    buildSegmentTree(arr, 2 * index + 2, mid + 1, end);

    // Internal node will have the minimum value of its children
    segmentTree[index] = min(segmentTree[2 * index + 1], segmentTree[2 * index + 2]);
}

// Function to find the minimum value in a given range [queryStart, queryEnd]
int findMinUsingSegmentTree(int index, int segmentStart, int segmentEnd, int queryStart, int queryEnd)
{
    // No overlap
    if (segmentEnd < queryStart || segmentStart > queryEnd)
    {
        return INT_MAX; // Return a large value representing no overlap
    }

    // Complete overlap
    if (segmentStart >= queryStart && segmentEnd <= queryEnd)
    {
        return segmentTree[index];
    }

    // Partial overlap
    int mid = (segmentStart + segmentEnd) / 2;
    int leftMin = findMinUsingSegmentTree(2 * index + 1, segmentStart, mid, queryStart, queryEnd);
    int rightMin = findMinUsingSegmentTree(2 * index + 2, mid + 1, segmentEnd, queryStart, queryEnd);
    return min(leftMin, rightMin);
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
    cout << "Segment tree: ";
    for (int value : segmentTree)
    {
        cout << value << " ";
    }
    cout << endl;

    // Process each query
    cout << "Query results: ";
    for (const auto &query : queries)
    {
        int queryStart = query.first;
        int queryEnd = query.second;
        int minValue = findMinUsingSegmentTree(0, 0, n - 1, queryStart, queryEnd);
        cout << minValue << " ";
    }
    cout << endl;

    return 0;
}
