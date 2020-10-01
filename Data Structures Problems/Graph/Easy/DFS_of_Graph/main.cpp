#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void dfsUtils(vector<int> g[], vector<int> &dfsVec, unordered_set<int> &visited, int v){
    dfsVec.emplace_back(v);
    visited.emplace(v);

    for(int new_v : g[v])
        if(visited.count(new_v) == 0)
            dfsUtils(g, dfsVec, visited, new_v);
}

vector <int> dfs(vector<int> g[], int N){
    vector<int> dfsVec;

    unordered_set<int> visited;
    dfsUtils(g, dfsVec, visited, 0);

    return dfsVec;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;

        vector<int> g[N];
        bool vis[N];

        memset(vis, false, sizeof(vis));

        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
