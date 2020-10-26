#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool negativeCycleExists(unordered_map<int, vector<pair<int,int>>> &graph, int V){
    int pathLength;


    for(){

    }
}


int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int v,e;cin>>v>>e;

        unordered_map<int,vector<pair<int,int>>> graph(v);
        for(int j = 0 ; j < e ; j++){
            int src,des,weight;
            cin>>src>>des>>weight;

            graph[src].emplace_back(make_pair(des, weight));
        }

        cout<<negativeCycleExists(graph, v)<<endl;
    }
}
