bool BFS(unordered_map<int, vector<int>> &adjList, vector<bool> &visited, int &src, int &dst)
{
    // bfs traversal karan hai
    if (src == dst)
        return true;
    queue<int> q;
    q.push(src); // src ko invitation bej diya
    // abh isko vaps nahi bulana hai party me
    visited[src] = true;
    while (!q.empty())
    {
        // jabtak meri q empty nahi ho jati hai
        // baki logo ko bhi invitation bejo
        int u = q.front();
        q.pop();
        for (auto v : adjList[u])
        {
            if (!visited[v])
            {
                if (v == dst)
                    return true; // src sy destination phuch sakte hai
                q.push(v);
                visited[v] = true;
            }
        }
    }

    return false;
}

// leet 1971
bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    // m to bsf algo janta hu pahchanta hu
    if (source == destination)
        return true;
    unordered_map<int, vector<int>> adjList;

    // abh adjmatrix --> adjList

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        // sabke liye check karna hai ki source sy destination ka path hai ya nahi
        if (!visited[i])
        {
            bool ans = BFS(adjList, visited, source, destination);
            if (ans)
                return true;
        }
    }

    return false;
}