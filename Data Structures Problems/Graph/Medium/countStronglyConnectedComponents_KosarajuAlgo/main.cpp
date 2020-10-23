// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

 // } Driver Code Ends


/*  Function to find the number of strongly connected components
*   using Kosaraju's algorithm
*   V: number of vertices
*   adj[]: array of vectors to represent graph
*/



void reverseGraph(vector<int> adj[], vector<int> revAdj[], int N){
    for(int v = 0 ; v < N ; v++)
        for(int des: adj[v])
            revAdj[des].emplace_back(v);
}

void firstDfs(vector<int> adj[], int src, int visited[], stack<int> &s){
    cout<<"first"<<endl;
    visited[src] = true;

    for(int v:adj[src]){
        if(not visited[v]){
            firstDfs(adj, v, visited, s);
            s.emplace(v);
        }
    }
}

void firstDfsLoop(vector<int> adj[], stack<int> &s, int V){
    cout<<"fistL"<<endl;
    int visited[V];
    memset(visited, false, sizeof(visited));

    for(int i = 0 ; i < V ; i++){
        if(not visited[i]){
            firstDfs(adj, i, visited, s);
            s.emplace(i);
        }
    }
}

void secondDfs(vector<int> adj[], int s, int visited[]){
    cout<<"second"<<endl;
    visited[s] = true;

    for(int v:adj[s]){
        if(not visited[v]){
            secondDfs(adj, v, visited);
        }
    }
}



int kosaraju(int V, vector<int> adj[]){
    stack<int> s;

    firstDfsLoop(adj, s, V);

    vector<int> revAdj[V];
    reverseGraph(adj, revAdj, V);

    int componentCount=0;
    int visited[V];
    memset(visited, false, sizeof(visited));

    while(not s.empty()){
        int top_v = s.top();s.pop();

        if(not visited[top_v]){
            secondDfs(revAdj, top_v, visited);
            componentCount++;
        }
    }

    return componentCount;
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int m, n;
        vector<int> adj[a];
        for (int i = 0; i < b; i++) {
            cin >> m >> n;
            adj[m].push_back(n);
        }
        cout << kosaraju(a, adj) << endl;
    }
    return 0;
}
