#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// V: number of vertices
void printGraph(vector<int> adj[], int V){
    for(int i = 0 ; i < V ; i++){
        vector<int> list = adj[i];
        cout<<i;
        for(int j = 0 ; j < list.size() ; j++){
            if(j == 0)
                cout<<"-> ";
            cout<<list[j];
            if(j != list.size() - 1)
                cout<<"-> ";
        }
        cout<<endl;
    }
}



int main()
{
   int t;
   cin>>t;
   while(t--)
    {  int v, e;
       cin>>v>>e;
       int a, b;
       vector<int> adj[v];
       for(int i=0;i<e;i++)
       {
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
       }
        printGraph(adj, v);

     }
    return 0;
}
