#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

unordered_map<int, int> parent;
class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    // void bfs
    void addEdge(int u, int v)
    {
        // undireted
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void printList()
    {
        for (auto nodes : adjList)
        {
            cout << nodes.first << " -> ";
            for (auto nbr : nodes.second)
            {
                cout << nbr << " , ";
            }
            cout << endl;
        }
    }

    void dfs(int src)
    {

        if (!visited[src])
        {
            visited[src] = true;
            cout << src << " ";
            for (auto nbr : adjList[src])
            {
                dfs(nbr);
                visited[nbr] = true;
            }
        }
    }

    bool checkCycleUsingDFS(int src)
    {
        if (!visited[src])
        {
            visited[src] = true;
            for (auto nbr : adjList[src])
            {
                parent[src] = nbr;
                bool checkans = checkCycleUsingDFS(nbr);
                if(checkans){
                    return true;
                }
                visited[nbr] = true;
            }
        }
        else if (visited[src] && parent[src] != src)
        {
            return true;
        }
        else
        {
            return false;
        }
        return false;
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
  

    int src = 0;
    parent[src] = -1;
    bool ans = g.checkCycleUsingDFS(src);
    if (ans)
    {
        cout << "cycle is present" << endl;
    }
    else
    {
        cout << "cycle is not present" << endl;
    }

    return 0;
}