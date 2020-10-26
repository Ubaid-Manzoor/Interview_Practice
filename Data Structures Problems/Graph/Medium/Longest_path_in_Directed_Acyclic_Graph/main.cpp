#include <iostream>
#include <limits.h>
#include <list>
#include <stack>
#include <string.h>
#define NINF INT_MIN
using namespace std;


class AdjListNode {
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w)
    {
        v = _v;
        weight = _w;
    }
    int getV() { return v; }
    int getWeight() { return weight; }
};


class Graph {
    int V;

    list<AdjListNode>* adj;

public:
    Graph(int V);
    ~Graph();

    void addEdge(int u, int v, int weight);
    void longestPath(int s);
    void topologicalOrdering(int v, stack<int> &st, bool visited[]);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<AdjListNode>[V];
}

Graph::~Graph() {
    delete [] adj;
}

void Graph::addEdge(int u, int v, int weight){
    AdjListNode node(v, weight);
    adj[u].push_back(node); // Add v to u's list
}

void Graph::topologicalOrdering(int v, stack<int> &st, bool visited[]){
    visited[v] = true;

    for(AdjListNode desNode: adj[v])
        if(not visited[desNode.getV()])
            topologicalOrdering(desNode.getV(), st, visited);

    st.push(v);
}

void Graph::longestPath(int s){
    stack<int> st;
    bool visited[V];
    memset(visited, false, sizeof(visited));

    for(int i = 0 ; i < V ; i++)
        if(not visited[i])
            topologicalOrdering(i, st, visited);

    int dist[V];
    for(int v = 0 ; v < V ; v++)
        dist[v] = INT_MIN;

    dist[s] = 0;
    while(not st.empty()){
        int top_v = st.top();st.pop();

        for(AdjListNode desNode: adj[top_v]){
            if(dist[desNode.getV()] < dist[top_v] + desNode.getWeight()){
                dist[desNode.getV()] = dist[top_v] + desNode.getWeight();
            }
        }
    }


    for(int v = 0 ; v < V ; v++){
        cout<<"from "<<s<<" to "<<v<<" is "<<dist[v]<<endl;
    }
}

// Driver program to test above functions
int main()
{
    // Create a graph given in the above diagram.
    // Here vertex numbers are 0, 1, 2, 3, 4, 5 with
    // following mappings:
    // 0=r, 1=s, 2=t, 3=x, 4=y, 5=z
    Graph g(6);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    int s = 1;
    cout << "Following are longest distances from "
            "source vertex "
         << s << " \n";
    g.longestPath(s);

    return 0;
}
