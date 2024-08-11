#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int,int>parent;

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

    void bfs(int src)
    {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty())
        {
            int frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    bool chechcycleUsingBfs(int src){
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

         while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto nbr : adjList[frontNode])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] && nbr != parent[frontNode] ){
                    
                    return true;

                }
            }

        }      

        return false;
    }

   
};

int main()
{
    Graph g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,5);
    g.addEdge(2,6);
    g.addEdge(5,6);

    // g.printList();
    
    bool ans = g.chechcycleUsingBfs(0);
    if(ans){
        cout<<"cycle is present"<<endl;
    }
    else{
        cout<<"cycle is not present"<<endl;
    }
    // g.bfs(0);

    return 0;
}