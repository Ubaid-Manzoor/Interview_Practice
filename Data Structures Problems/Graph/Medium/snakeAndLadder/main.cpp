#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define R 5
#define C 6



int minimumDiceThrowen(unordered_map<int,int> &snake_ladder_edges){

    queue<pair<int,int>> q;
    q.emplace(make_pair(1,0));
    int visited[31];
    memset(visited, false, sizeof(visited));

    while(not q.empty()){
        pair<int,int> front = q.front();q.pop();
        int v = front.first;
        int pathLength = front.second;
        visited[v] = true;

        for(int i = v + 1 ; i <= v + 6 and i <= 30 ; i++){
            if(not visited[i]){
                if(i == 30)
                    return pathLength + 1;

                if(snake_ladder_edges.count(i) == 0)
                    q.emplace(make_pair(i, pathLength+1));
                else if(i < snake_ladder_edges[i] and not visited[snake_ladder_edges[i]])
                    q.emplace(make_pair(snake_ladder_edges[i], pathLength+1));
            }
        }
    }
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        unordered_map<int,int> snake_ladder_edges(n);
        for(int j = 0 ; j < n ; j++){
            int src;cin>>src;
            int des;cin>>des;
            snake_ladder_edges[src] = des;
        }

        cout<<minimumDiceThrowen(snake_ladder_edges)<<endl;
    }
}
