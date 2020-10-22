#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// a structure to represent a weighted edge in graph
struct Edge {
    int src, dest, weight;
    Edge(int s, int d, int w){
        src = s;
        dest = d;
        weight = w;
    }
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph {
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    vector<Edge> edges;

    Graph(int V, int E){
        this->V = V;
        this->E = E;

        edges.reserve(E);
    }
};

void printDist(int dist[], int V){
    for(int i = 0 ; i < V ; i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
}

void BellmanFord(Graph graph, int s){
    int V = graph.V;
    int E = graph.E;
    int dist[V];

    for(int i = 0 ; i < V ; i++)
        dist[i] = INT_MAX;

    dist[s] = 0;

    for(int i = 0 ; i < V ; i++){
        bool improved=false;
        for(Edge e: graph.edges){
            if(dist[e.src] + e.weight < dist[e.dest]){
                dist[e.dest] = dist[e.src] + e.weight;
                improved = true;
            }
        }

        if(not improved)
            break;

        for(Edge e: graph.edges){
            if(dist[e.src] + e.weight < dist[e.dest]){
                cout<<"Negative Cycle Exists"<<endl;
                return;
            }
        }
    }

    printDist(dist, V);
}


// Driver program to test above functions
int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph graph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph.edges.emplace_back(Edge(0,1,-1));

    // add edge 0-2 (or A-C in above figure)
    graph.edges.emplace_back(Edge(0,2,4));

    // add edge 1-2 (or B-C in above figure)
    graph.edges.emplace_back(Edge(1,2,3));

    // add edge 1-3 (or B-D in above figure)
    graph.edges.emplace_back(Edge(1,3,2));

    // add edge 1-4 (or A-E in above figure)
    graph.edges.emplace_back(Edge(1,4,2));

    // add edge 3-2 (or D-C in above figure)
    graph.edges.emplace_back(Edge(3,2,5));

    // add edge 3-1 (or D-B in above figure)
    graph.edges.emplace_back(Edge(3,1,1));

    // add edge 4-3 (or E-D in above figure)
    graph.edges.emplace_back(Edge(4,3,-3));

    BellmanFord(graph, 0);

    return 0;
}
