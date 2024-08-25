#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);

    // undirected
    adjList[v].push_back(u);
    return;
}

void printGraph(vector<int> adjList[],int v)
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
        cout<<endl;
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

    printGraph(adjList,v);

    return 0;
}