#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

stack<int> st;
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
            // cout << src << " ";
            for (auto nbr : adjList[src])
            {
                dfs(nbr);
                visited[nbr] = true;
            }
        }
    }
    
    void TopoSortDfs(int src)
    {

        if (!visited[src])
        {
            visited[src] = true;
            for (auto nbr : adjList[src])
            {
                TopoSortDfs(nbr);
                visited[nbr] = true;
            }
        }
        st.push(src);
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 6);
    g.addEdge(6, 7);

   
    cout << "Topo Sort " << endl;
    g.TopoSortDfs(0);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    

    return 0;
}