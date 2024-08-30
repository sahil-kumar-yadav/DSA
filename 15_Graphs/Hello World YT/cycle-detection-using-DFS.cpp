#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

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

bool checkCycleDFS(vector<int> adjList[], vector<bool> &visited, unordered_map<int, int> &parent, int src)
{
    visited[src] = true;
    bool aageKaAns = false;
    // cout << "Visiting node: " << src << endl;
    // cout << "Neighbors of node " << src << ": ";

    for (auto v : adjList[src])
    {
        // cout << v << " ";
        if (!visited[v])
        {
            parent[v] = src;
            // cout << "(Tree Edge) Moving to node " << v << " from node " << src << endl;
            aageKaAns = checkCycleDFS(adjList, visited, parent, v);
            if (aageKaAns)
                return aageKaAns;
        }
        else if (parent[src] != v)// visited and is not the parent of src
        {
            // cout << "(Back Edge) Cycle detected between node " << src << " and node " << v << endl;
            return true;
        }
       
    }

    return aageKaAns;
    cout << endl; // Newline for better readability
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
    int v = 9;
    vector<int> adjList[v]; // array of vector for vetex

    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 2);
    // addEdge(adjList, 2, 3); // yaha cycle hai
    addEdge(adjList, 3, 4);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 5);
    addEdge(adjList, 5, 6);
    addEdge(adjList, 6, 7);
    // addEdge(adjList, 6, 8); //yaha cycle hai
    addEdge(adjList, 7, 8);

    BFS(adjList, v);
    cout << endl;

    // NOW DFS traversal
    vector<bool> visited(v, false);
    unordered_map<int, int> parent;
    parent[0] = -1;
    visited[0] = true;
    bool ans = checkCycleDFS(adjList, visited, parent, 0);

    if (ans)
    {
        cout << "cycle is present";
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    return 0;
}