int BS(vector<int> arr, int n)
{
    int ans = -1;
    int start = 0, end = n - 1;
    int mid = (start + end) / 2;

    while (start <= end)
    {
        if (arr[mid] == mid)
        {
            ans = mid;
            // return true
            end = mid - 1;
            // break;
        }
        else if (arr[mid] < mid)
        {
            start = mid + 1;
        }
        else
        {
            // arr[mid] > target
            end = mid - 1;
        }
        mid = (start + end) / 2;
    }

    return ans;
}

int findMagicalNumber(int N, vector<int> &arr)
{
    // code here
    int ans = BS(arr, N);

    return ans;
}