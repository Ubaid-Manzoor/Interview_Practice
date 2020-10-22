// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends

int getMin(int dist[], bool visited[], int V){

    int Vertex;
    int minValue=INT_MAX;
    for(int i = 0 ; i < V ; i++)
        if(not visited[i] and dist[i] < minValue)
            minValue=dist[i], Vertex=i;

    return Vertex;
}

int spanningTree(int V, int E, vector<vector<int>> &graph){
    bool visited[V];
    int dist[V];
    for(int i = 0 ; i < V ; i++)
        dist[i] = INT_MAX, visited[i] = false;
    dist[0] = 0;

    int spanned=0;

    int minSum=0;
    while(spanned < V){
        int minVertex = getMin(dist, visited, V);
        minSum += dist[minVertex];
        visited[minVertex] = true;

        for(int v = 0 ; v < V ; v++){
            if(graph[minVertex][v] != INT_MAX and not visited[v]){
                if(graph[minVertex][v] < dist[v]){
                    dist[v] = graph[minVertex][v];
                }
            }
        }

        spanned++;
    }

    return minSum;
}


























