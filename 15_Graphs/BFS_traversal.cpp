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

    void bfs(int src){
        cout<<"BfS traversal "<<endl;
        // level order traversal
        queue<int>q;
        q.push(src);
        visited[src] = true;
        
        while(!q.empty()){
            int frontNode = q.front();
            visited[frontNode] = true;
            cout<<frontNode<<" ";
            q.pop();

            for(auto neighbour:adjList[frontNode]){
                // sabko q my push kardo 
                if(!visited[neighbour]){
                    q.push(neighbour);
                    // visited[neighbour] = true;
                }
                
            }
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
                visited[nbr] = true; // required hai // varna wrong ans aayega
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.printList();
    // cout<<"bfs traversal "<<endl;
    // g.bfs(0);
    cout << "dfs traversal " << endl;
    g.dfs(0);

    return 0;
}