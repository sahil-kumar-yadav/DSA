#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
#include<algorithm>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    void printList()
    {
        for (auto node : adjList)
        {
            cout << node.first << " -> ";
            for (auto nbr : adjList[node.first])
            {
                cout << nbr << ", ";
            }
            cout << endl;
        }
    }

    void shortestPathUsingBfs(int src, int dest)
    {

        visited[src] = true;
        parent[src] = -1;
        q.push(src);

        // set parent
        while (!q.empty())
        {
            int fNode = q.front();
            // cout << fNode << " ";
            q.pop();

            for (auto nbr : adjList[fNode])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = fNode;
                    q.push(nbr);
                }
            }
        }

        // now traverse from destination to src
        vector<int> ans;

        int node = dest;
        // -1 becuz humne src ka parent -1 set kar rakha hai uper
        while (node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        // reversing the ans
        reverse(ans.begin(),ans.end());

        // printing the ans
        cout << "printing the ans " << endl;
        for (auto i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;
    // g.addEdge(0, 1);
    // g.addEdge(1, 2);
    // g.addEdge(2, 3);
    // g.addEdge(3, 4);
    // g.addEdge(0, 5);
    // g.addEdge(5,4);
    // g.addEdge(0, 6);
    // g.addEdge(6,7);
    // g.addEdge(7,8);
    // g.addEdge(8,4);

    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(2,5);
    g.addEdge(1,4);
    g.addEdge(3,6);
    g.addEdge(4,5);
    g.addEdge(6,5);

    // g.printList();
    g.shortestPathUsingBfs(0, 5);

    return 0;
}