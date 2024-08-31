#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
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

bool DetectCycleUsingDFS(vector<int> adjList[], vector<bool> &visited, vector<bool> DFSvisited, int src)
{
    visited[src] = true;
    DFSvisited[src] = true;
    for (auto v : adjList[src])
    {
        if (visited[v] && DFSvisited[v])
        {
            return true;
        }
        else if (!visited[v])
        {
            return DetectCycleUsingDFS(adjList, visited, DFSvisited, v);
        }
    }
    DFSvisited[src] = false;
    return false;
}

int main()
{
    int v = 8;
    vector<int> adjList[v];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 1, 4);
    addEdge(adjList, 4, 3);
    addEdge(adjList, 5, 0);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 6, 7);
    // addEdge(adjList, 7, 5); // yaha cycle hai

    printGraph(adjList, v);
    cout << "Printing BFS traversal " << endl;
    cout << endl;

    // NOW DFS traversal
    vector<bool> visited(v, false);
    vector<bool> DFSvisited(v, false);
    bool ans = false;

    for (int i = 0; i < v; i++)
    {

        ans = DetectCycleUsingDFS(adjList, visited, DFSvisited, i);
        if (ans)
            break;
    }

    if (ans)
    {
        cout << "Cycle present" << endl;
    }
    else
    {
        cout << "Cycle not present" << endl;
    }

    return 0;
}