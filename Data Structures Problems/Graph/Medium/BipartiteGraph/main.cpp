// { Driver Code Starts
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
    cin>>t;
    int g[MAX][MAX];
    while(t--)
    {
        memset(g,0,sizeof (g));
        int n;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>g[i][j];
            }
        }

        cout<<isBipartite(g,n)<<endl;
    }
    return 0;
}
// } Driver Code Ends

#define log(x) cout<< #x <<" is equal to "<<x<<endl

bool dfs(int G[][MAX], int v, unordered_set<int> &set1, unordered_set<int> &set2, int V){
    for(int des_v = 0 ; des_v < V ; des_v++){
        if(G[v][des_v]){
            if(set1.find(des_v) != set1.end() and set1.find(v) != set1.end())
                return false;
            if(set2.find(des_v) != set2.end() and set2.find(v) != set2.end())
                return false;

            if(set1.count(des_v) == 0 and set2.count(des_v) == 0){
                if(set1.count(v))
                    set2.emplace(des_v);
                else
                    set1.emplace(des_v);
                if(not dfs(G, des_v, set1, set2, V))
                    return false;
            }
        }


    }

    return true;
}

/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int V){
     unordered_set<int> set1,set2;
//     bool visited[V];
//     memset(visited, false, sizeof(visited));

     for(int i = 0 ; i < V ; i++){
         if(set1.count(i) == 0 and set2.count(i) == 0){
            set1.emplace(i);
            if(not dfs(G, i, set1, set2, V))
                return false;
         }
     }

     return true;
}






















