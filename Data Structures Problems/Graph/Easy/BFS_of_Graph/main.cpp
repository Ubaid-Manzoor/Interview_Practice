// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector <int> bfs(vector<int> g[], int N);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;
        vector<int> adj[N];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            cout<<u<<"->"<<v<<endl;
            adj[u].push_back(v);
        }
        vector <int> res = bfs(adj, N);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout << endl;
    }
}// } Driver Code Ends

vector <int> bfs(vector<int> g[], int N) {
    // Your code here
    queue<int> q;

    q.emplace(0);
    vector<int> bfsVec;
    unordered_set<int> visited;
    while(not q.empty()){
        int vertex = q.front();q.pop();
        if(visited.count(vertex) == 0){
            bfsVec.emplace_back(vertex);
            visited.emplace(vertex);
            for(int v : g[vertex])
                q.emplace(v);
        }
    }

    return bfsVec;
}
