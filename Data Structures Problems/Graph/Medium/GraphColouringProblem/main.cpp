#include <iostream>
#include <list>
#include <string.h>
using namespace std;

// A class that represents an undirected graph
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // A dynamic array of adjacency lists
public:
    // Constructor and destructor
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }

    // function to add an edge to graph
    void addEdge(int v, int w);

    // Prints greedy coloring of the vertices
    void greedyColoring();
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);  // Note: the graph is undirected
}

// Assigns colors (starting from 0) to all vertices and prints
// the assignment of colors


void Graph::greedyColoring() {
    int assigned[V];
    for(int i = 0 ; i < V ; i++)
        assigned[i] = -1;

    assigned[0] = 0;

    for(int v = 1 ; v < V ; v++){
        bool adjColors[V];
        memset(adjColors, false, sizeof(adjColors));

        for(int u: adj[v]){
            if(assigned[u] != -1){
                adjColors[assigned[u]] = true;
            }
        }

        for(int c = 0 ; c < V ; c++){
            if(not adjColors[c]){
                assigned[v] = c;
                break;
            }
        }
    }


    for(int v = 0 ; v < V ; v++){
        cout<<"Vertex : "<<v<<" has Assigned -> "<<assigned[v]<<endl;
    }
}

// Driver program to test above function
int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Coloring of graph 1 \n";
    g1.greedyColoring();

    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColoring of graph 2 \n";
    g2.greedyColoring();

    return 0;
}
