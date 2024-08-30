#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    return;
}

void printGraph(vector<int> adjList[], int v)
{

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

void TopoSortDFS(vector<int> adjList[], vector<bool> &visited, int src, stack<int> &st)
{
    // cout << src << " ";
    if(visited[src]) return;
    visited[src] = true;

    for (auto nbr : adjList[src])
    {
        if (!visited[nbr])
        {
            TopoSortDFS(adjList, visited, nbr, st);
        }
    }
    st.push(src);
}

int main()
{
    int v = 5;
    vector<int> adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 3, 4);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 2, 4);

    printGraph(adjList, v);
    cout << endl;

    // NOW DFS traversal
    vector<bool> visited(v, false);
    stack<int> st;

    // disjoint graph
    for (int i = 0; i < v; i++)
    {
        TopoSortDFS(adjList, visited, i, st);
    }

    cout << "Printing toposort " << endl;
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}