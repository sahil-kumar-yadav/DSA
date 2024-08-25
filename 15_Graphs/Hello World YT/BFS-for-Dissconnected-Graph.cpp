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

void BFS(vector<int> adjList[], int src, vector<bool> &visited)
{
    // Immidiate Friend and then they give to their immediate friends
    // ek baar kisi dost ko party de di to vaps nahi deni
    
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
    int v = 16;
    vector<int> adjList[v]; // array of vector for vetex

    addEdge(adjList, 0, 1);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 3);

    // graph 2
    addEdge(adjList, 3, 4);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 5, 6);
    // graph 3
    addEdge(adjList, 7, 8);
    addEdge(adjList, 8, 9);
    // graph 4
    addEdge(adjList, 10, 11);
    addEdge(adjList, 11, 12);
    // graph 5
    addEdge(adjList, 13, 14);
    addEdge(adjList, 14, 15);

    // 0 -> 1 // 0 -> 2 // 1->2 // Graph 1
    // 3->4 // 4-> 5 //  5 ->6  // Graph 2

    printGraph(adjList, v);
    cout << "Printing BFS traversal " << endl;
    vector<bool> visited(v, false);
    for (int i = 0; i < v; i++)
    {
        int src = i;
        if (!visited[i])
            BFS(adjList, src, visited);
    }

    return 0;
}