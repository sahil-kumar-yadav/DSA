void BFS(unordered_map<int, vector<int>> &adjList, int src, vector<bool> &visited)
{
    // BFS logic
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        // front

        int u = q.front();
        q.pop();

        for (auto v : adjList[u])
        {
            if (!visited[v])
            {
                // agar phele sy invite nahi kar rakha hai to
                q.push(v); // invited to party
                visited[v] = true;
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{

    unordered_map<int, vector<int>> adjList;

    int v = isConnected.size();

    for (int i = 0; i < v; i++)
    {
        int u = i;
        for (int j = 0; j < v; j++)
        {

            if (isConnected[i][j])
            {
                int v = j;
                adjList[u].push_back(v);
            }
        }
    }
    vector<bool> visited(v, false);
    int count = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            BFS(adjList, i, visited);
            count++;
        }
    }

    return count;
}