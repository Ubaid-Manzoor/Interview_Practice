#include<bits/stdc++.h>
using namespace std;

// iPair ==>  Integer Pair
typedef pair<int, int> iPair;


class Graph
{
    int V;    // No. of vertices

    list< pair<int, int> > *adj;
    bool pathMoreThanKUtil(int src, int k, vector<bool> &path);


public:
    Graph(int V);  // Constructor

    void addEdge(int u, int v, int w);
    bool pathMoreThanK(int src, int k);
};

bool Graph::pathMoreThanKUtil(int src, int k, vector<bool> &path ){
    if(k <= 0)
        return true;

    path[src] = true;

    for(pair<int,int> desNode: adj[src])
        if(not path[desNode.first])
            if(pathMoreThanKUtil(desNode.first, k - desNode.second, path))
                return true;
    path[src] = false;
    return false;
}

bool Graph::pathMoreThanK(int src, int k){
    vector<bool> path(V,false);

    return pathMoreThanKUtil(src, k, path);
}





// Allocates memory for adjacency list
Graph::Graph(int V){
    this->V = V;
    adj = new list<iPair> [V];
}

// Utility function to an edge (u, v) of weight w
void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);

    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int src = 0;
    int k = 62;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
                             cout << "No\n";

    k = 60;
    g.pathMoreThanK(src, k)? cout << "Yes\n" :
                             cout << "No\n";

    return 0;
}
