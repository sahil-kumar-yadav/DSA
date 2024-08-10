vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    // Your code here

    stack<long long> st;
    vector<long long> ans(n, -1);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] > arr[st.top()])
        {
            long long index = st.top();
            ans[index] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}