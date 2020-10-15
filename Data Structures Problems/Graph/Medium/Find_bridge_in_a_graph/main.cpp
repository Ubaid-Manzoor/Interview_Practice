// { Driver Code Starts
// Initial template
#include <bits/stdc++.h>
using namespace std;

bool isBridge(list<int> adj[], int V, int u, int v);
// Driver Program
int main() {

    int T;
    cin >> T;
    while (T--) {
        int s, N;
        cin >> s >> N;
        list<int> *adj = new list<int>[s];
        for (int i = 0; i < N; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        int a, b;
        cin >> a >> b;

        if (isBridge(adj, s, a, b))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}
// } Driver Code Ends


// your task is to complete this function

/*
adj : adjacency list of the graph
V : Number of vertices
s,e : End vertices of the given edge
*/


bool findUsingDfs(list<int> adj[], int s, int e, bool visited[]){
    if(visited[s])
        return false;

    if(s == e)
        return true;

    visited[s] = true;
    for(int v: adj[s]){
        bool found = findUsingDfs(adj, v, e, visited);
        if(found)
            return true;
    }

    return false;
}

bool isReachable(list<int> adj[], int V, int s, int e){
    bool visited[V];
    for(int i = 0 ; i < V; i++)
        visited[i] = false;

    return findUsingDfs(adj, s, e, visited);
}

bool isBridge(list<int> adj[], int V, int s, int e) {
    adj[s].remove(e);
    adj[e].remove(s);

    if(isReachable(adj, V, s, e))
        return false;
    return true;
}
