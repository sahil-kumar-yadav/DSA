# Graph

## implementation Using Adjcency List

```cpp
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
```

## implementation Using Adjcency list
```cpp
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
```

## BFS traversal
```cpp
#include <iostream>
#include <list>
#include <unordered_map>
#include<queue>

using namespace std;

// implementation of graph using adj list
class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    unordered_map<int,bool> visited;

    void addEdge(int u, int v, bool direction = 0)
    {
        // create a edge from u to v
        adjList[u].push_back(v);

        // if direction is 0 --> undirected
        // if direction is 1 -- directed

        if (!direction)
        {
            // create a edge v to u
            adjList[v].push_back(u);
        }
    }

    void printGraph()
    {
        for (auto it : adjList)
        {
            int Node = it.first;
            cout << Node << "-> ";
            auto list = it.second;

            for (auto ptr : list)
            {
                cout << ptr << " , ";
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
};

int main()
{
    Graph g;
    // directed
    // g.addEdge(0,1,1);
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,1);
    // g.addEdge(3,7,1);
    // g.addEdge(3,5,1);
    // g.addEdge(7,6,1);
    // g.addEdge(7,4,1);


    // undirected 
    g.addEdge(0,1,0);
    g.addEdge(1,2,0);
    g.addEdge(1,3,0);
    g.addEdge(3,7,0);
    g.addEdge(3,5,0);
    g.addEdge(7,6,0);
    g.addEdge(7,4,0);


    g.printGraph();

    g.bfs(1);
    return 0;
}
```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

## 
```cpp

```

