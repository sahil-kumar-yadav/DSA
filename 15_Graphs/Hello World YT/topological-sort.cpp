#include <iostream>
#include <vector>
#include <queue>

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

void TopoSort(vector<int> adjList[], int v, vector<int> &Indegree)
{

    vector<bool> visited(v, false);
    queue<int> q;
    // jinki indegree 0 hai unko q my push kardo
    for (int i = 0; i < Indegree.size(); i++)
    {
        if (Indegree[i] == 0)
        {
            q.push(i);
            visited[i] = true;
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (auto v : adjList[u])
        {
            Indegree[v]--;
            if (!visited[v] && Indegree[v] == 0)
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
}

void calculateIndegree(vector<int> adjList[], int v, vector<int> &Indegree)
{
    for (int i = 0; i < v; i++)
    {
        for (auto it : adjList[i])
        {
            Indegree[it]++;
        }
    }

    // printing indegree
    cout << "Printing Indegree " << endl;
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> " << Indegree[i] << endl;
    }
}

int main()
{
    int v = 5;
    vector<int> adjList[v]; // array of vector for vetex

    addEdge(adjList, 0, 2);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 2, 3);
    addEdge(adjList, 1, 3);
    addEdge(adjList, 1, 4);

    // printGraph(adjList, v);
    vector<int> Indegree(v, 0);
    calculateIndegree(adjList, v, Indegree);

    cout << "Printing TopoSort " << endl;

    TopoSort(adjList, v, Indegree);

    return 0;
}