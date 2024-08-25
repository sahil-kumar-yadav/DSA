#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);

    // undirected
    adjList[v].push_back(u);
    return;
}

void printGraph(vector<int> adjList[], int v)
{
    // for (auto vertex : adjList[0])
    // {
    //     cout << vertex << " -> ";
    //     for (auto nbr : vertex)
    //     {
    //         cout << nbr << " , ";
    //     }
    // }
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto it : adjList[i])
        {
            cout << it << " , ";
        }
        cout << endl;
    }
}

void BFS(vector<int> adjList[], int v)
{
    // Immidiate Friend and then they give to their immediate friends
    // ek baar kisi dost ko party de di to vaps nahi deni
    int src = 0;
    // cout << "src " << src;
    vector<bool> visited(v, false);
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " "; // print to karvana padega na
        q.pop();

        for (auto v : adjList[u])
        {
            // jitne bhi nbr hai ya friends hai unko party ka invite dedo
            // but agar koi phele sy party le chuka hai usko hatana padega na list sy
            if (!visited[v])
            {
                q.push(v);         // invitation bej do
                visited[v] = true; // check mark kardo
            }
        }
    }
}
int main()
{
    int v = 4;
    vector<int> adjList[4]; // array of vector for vetex
    // 0
    // 1
    // 2
    // 3
    // eesa bana diya

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);

    printGraph(adjList, v);
    cout << "Printing BFS traversal " << endl;
    BFS(adjList, v);

    return 0;
}