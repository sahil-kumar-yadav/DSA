#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        // direction - 0 // undirected graph/edge
        // direction - 1 // directed graph
        // edge u to v
        adjList[u].push_back(v);
        if(direction == 0){
            // undirected edge
            // edge v to u
            adjList[v].push_back(u);
        }

    }

    void printAdjList(){
        for(auto nodes:adjList){
            cout<<nodes.first <<" -> ";
            for(auto neighbour:nodes.second){
                cout<<neighbour<<", ";
            }
            cout<<endl;
        }
    }
    




};

int main()
{
    Graph g;
    // directed
    g.addEdge(0,2,1);
    g.addEdge(1,2,1);
    g.addEdge(1,0,1);
    g.printAdjList();




    // undirected 
    // g.addEdge(0,1,0);
    // g.addEdge(1,2,0);
    // g.addEdge(0,2,0);
    // g.printAdjList();
    return 0;
}