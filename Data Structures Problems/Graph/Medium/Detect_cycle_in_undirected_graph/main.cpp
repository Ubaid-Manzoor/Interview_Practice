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

bool bfs(vector<int> g[],unordered_set<int> &visited, int v){
    queue<pair<int,int>> q;
    q.emplace(make_pair(v,-1));

    while(not q.empty()){
        pair<int,int> p = q.front();q.pop();
        int current_vertex = p.first;
        int parent_vertex = p.second;

        visited.emplace(current_vertex);

        for(int new_v: g[current_vertex]){
            if(new_v == parent_vertex)
                continue;
            if(visited.count(new_v) == 1)
                return true;

            q.emplace(make_pair(new_v,current_vertex));
        }
    }

    return false;
}

void printGraph(vector<int> g[], int V){
    for(int i = 0 ; i < V ; i++){
        cout<<i<<"->";
        for(int vertex: g[i])
            cout<<vertex<<"->";
        cout<<endl;
    }
}


bool isCyclic(vector<int> g[], int V){
    unordered_set<int> visited;
    printGraph(g,V);

//    // Using DFS
//    for(int vertex = 0 ; vertex < V ; vertex++){
//        if(visited.count(vertex) == 0){
//            bool cycleExist = dfs(g, visited, vertex, -1);
//            if(cycleExist)
//                return true;
//        }
//    }
//    return false;


    // Using BFS

    for(int vertex = 0 ; vertex < V ; vertex++){
        if(visited.count(vertex) == 0){
//            cout<<"vertex :::: "<<vertex<<endl;
            bool cycleExist = bfs(g, visited, vertex);
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
//            cout<<u<<"->"<<v<<endl;
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}
  // } Driver Code Ends
