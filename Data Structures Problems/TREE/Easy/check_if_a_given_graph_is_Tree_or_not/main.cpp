#include<iostream>
#include <list>
#include <limits.h>
using namespace std;

// Class for an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj; // Pointer to an array for adjacency lists
    bool isCyclicUtil(int v, bool visited[], int parent);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);   // to add an edge to graph
    bool isTree();   // returns true if graph is tree
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    adj[w].push_back(v); // Add v to w’s list.
}

// A recursive function that uses visited[] and parent to
// detect cycle in subgraph reachable from vertex v.
bool Graph::isCyclicUtil(int v, bool visited[], int parent){
    cout<<"isCyclicUtil("<<v<<","<<"visited[]"<<")"<<endl;
    if(visited[v] == false)
        visited[v] = true;
    else
        return true;

    bool isCyclic=false;
    for(int vertex: adj[v]){
        if(vertex != parent)
            isCyclic = isCyclicUtil(vertex, visited, v);
        if(isCyclic)
            return isCyclic;
    }

    return isCyclic;
}


// Returns true if the graph is a tree, else false.
bool Graph::isTree()
{
    bool visited[V];
    for(int i = 0 ;i < V ; i++)
        visited[i] = false;

    bool isCyclic = isCyclicUtil(0, visited, -1);

    if(isCyclic)
        return false;

    for(int i = 0 ;i < V ; i++)
        if(not visited[i])
            return false;

    return true;
}

// Driver program to test above functions
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.isTree()? cout << "Graph is Tree\n":
                 cout << "Graph is not Tree\n";

    return 0;
}
