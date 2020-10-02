// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


/* This function is used to detect a cycle in undirected graph

*  g[]: array of vectors to represent graph
*  V: number of vertices
*/
bool dfs(vector<int> g[], unordered_set<int> &visited, int v, int parent){
    visited.emplace(v);

    for(int vertex: g[v]){
        if(visited.count(vertex) == 1 and vertex == parent)
            continue;

        if(visited.count(vertex) == 1)
            return true;

        bool cycleExist = dfs(g, visited, vertex, v);

        if(cycleExist)
            return true;
    }

    return false;
}

bool isCyclic(vector<int> g[], int V){
    unordered_set<int> visited;

    for(int vertex = 0 ; vertex < V ; vertex++){
        if(visited.count(vertex) == 0){
            bool cycleExist = dfs(g, visited, vertex, -1);
            if(cycleExist)
                return true;
        }
    }
    return false;
}

// { Driver Code Starts.


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;

        // array of vectors to represent graph
        vector<int> adj[V];

        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;

            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
