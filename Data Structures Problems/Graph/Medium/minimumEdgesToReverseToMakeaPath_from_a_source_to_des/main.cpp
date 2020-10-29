// Program to find minimum edge reversal to get
// atleast one path from source to destination
#include <bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f

class Graph
{
    int V;
    list< pair<int, int> > *adj;

public:
    Graph(int V);

    void addEdge(int u, int v, int w);

    vector<int> zero1Bfs(int src);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list< pair<int, int> >[V];
}


void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

Graph createUndirectedWeightedGraph(int edges[][2], int E, int V){
    Graph g(V);

    for(int i = 0 ; i < E ; i++){
        g.addEdge(edges[i][0], edges[i][1], 0);
        g.addEdge(edges[i][1], edges[i][0], 1);
    }

    return g;
}

vector<int> Graph::zero1Bfs(int src){
    vector<int> dist(V);
    for(int i = 0 ; i < V ;  i++)
        dist[i] = INT_MAX;

    deque<int> dq;
    dist[src] = 0;
    dq.emplace_back(src);

    while(not dq.empty()){
        int front_v = dq.front();dq.pop_front();
        for(pair<int,int> des_pair:adj[front_v]){
            int des_v = des_pair.first;
            int des_w = des_pair.second;
            if(dist[front_v] + des_w < dist[des_v]){
                dist[des_v] = dist[front_v] + des_w;

                if(des_w == 0)
                    dq.emplace_front(des_v);
                else
                    dq.emplace_back(des_v);
            }
        }
    }

    return dist;
}

int getMinEdgeReversal(int edges[][2], int E, int V, int src, int des){
    Graph g = createUndirectedWeightedGraph(edges, E, V);

    vector<int> dist = g.zero1Bfs(src);

    if(dist[des] == INT_MAX)
        return -1;
    return dist[des];
}



int main()
{
    int V = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {5, 1},
                     {4, 5}, {6, 4}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minEdgeToReverse = getMinEdgeReversal(edge, E, V, 0, 6);
    if (minEdgeToReverse != -1)
        cout << minEdgeToReverse << endl;
    else
        cout << "Not possible" << endl;
    return 0;
}
