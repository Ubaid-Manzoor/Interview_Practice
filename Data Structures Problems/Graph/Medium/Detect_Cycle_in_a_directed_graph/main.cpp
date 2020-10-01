// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool dfs(vector<int> adj[], unordered_set<int> &visited, vector<bool> &recStack, int V){
    if(recStack[V])
        return true;

    visited.emplace(V);
    recStack[V] = true;

    for(int vertex: adj[V]){
        bool cycleExists = dfs(adj, visited, recStack, vertex);
        recStack[vertex] = false;

        if(cycleExists)
            return true;
    }

    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    unordered_set<int> visited;
    vector<bool> recStack(V);

    for(int i = 0 ; i < V ; i++)
        recStack[i] = false;

        for(int vertex = 0 ; vertex < V ; vertex++){
            if(visited.count(vertex) == 0)
                if(dfs(adj, visited, recStack, vertex))
                    return true;
                recStack[vertex] = false;
    }

    return false;
}
int main() {

    int t;
    cin >> t;

    while(t--){

        int v, e;
        cin >> v >> e;

        vector<int> adj[v];

        for(int i =0;i<e;i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        cout << isCyclic(v, adj) << endl;

    }

    return 0;
}
