#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool HamiltonianPathExistsUtil(vector<list<int>> &graph,int v, bool path[], int pathSize){
    pathSize++;
    if(pathSize == graph.size())
        return true;

    path[v] = true;
    for(int u: graph[v]){
        if(not path[u]){
            if(HamiltonianPathExistsUtil(graph, u, path, pathSize))
                return true;
        }
    }
    path[v] = false;
    return false;
}

bool HamiltonianPathExists(vector<list<int>> &graph){
    int V = graph.size();
    bool path[V];
    memset(path, false, sizeof(path));

    for(int i = 0 ; i < V ; i++){
        if(HamiltonianPathExistsUtil(graph, i, path, 0))
            return true;
    }
    return false;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int V, E;cin>>V>>E;

        vector<list<int>> graph(V);
        for(int j = 0 ; j < E ; j++){
            int v,u;cin>>v>>u;
            v--;u--;
            graph[v].emplace_back(u);
            graph[u].emplace_back(v);
        }

        cout<<HamiltonianPathExists(graph)<<endl;
    }
}
