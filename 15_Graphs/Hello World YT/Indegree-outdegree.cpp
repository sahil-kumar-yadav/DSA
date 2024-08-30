// int townJudge = -1;
// unordered_map<int, vector<int>> adjList;

// for (auto it : trust) {
//     int u = it[0];
//     int v = it[1];
//     adjList[u].push_back(v);
// }

// for (int i = 1; i <= n; i++) {
//     if (adjList.find(i) == adjList.end()) {
//         // no entry exist
//         townJudge = i;
//     }
// }

// // check everybody trust town judge or not

// return townJudge;

// using concept of indegree and outdegree

vector<int> data(n + 1, 0);
for (auto it : trust)
{
    data[it[0]]--;
    data[it[1]]++;
}

for (int i = 1; i <= n; i++)
{
    int x = data[i];
    if (x == n - 1)
    {
        return i;
    }
}

return -1;