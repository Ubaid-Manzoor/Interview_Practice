// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

vector <int> dijkstra(vector<vector<int>> , int ,int );

int printSolution(vector <int> dist, int n)
{

   for (int i = 0; i < n; i++)
      printf("%d ", dist[i]);

}
int main()
{
    int t;
    int V;
    cin>>t;
    while(t--){
        cin>>V;

        vector<vector<int>> g(V);

        for(int i = 0;i<V;i++){
            vector<int> temp(V);
            g[i] = temp;
        }

        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                cin>>g[i][j];
            }
        }

        int s;
        cin>>s;

        vector <int> res = dijkstra(g, s, V);
        printSolution (res, V);
        cout<<endl;
       }
        return 0;
}// } Driver Code Ends


/*  Function to implement Dijkstra
*   g: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/

int getMinVextex(vector<int> dist, bool visited[], int V){
    int minDis = INT_MAX;
    int minVertex;

    for(int v = 0 ; v < V ; v++){
        if(not visited[v] and dist[v] < minDis){
            minDis = dist[v];
            minVertex = v;
        }
    }

    return minVertex;
}

vector <int> dijkstra(vector<vector<int>> g, int src, int V){
    vector<int> dist(V);
    bool visited[V];

    for(int i = 0 ; i < V ; i++)
        dist[i] = INT_MAX, visited[i] = false;

    dist[src] = 0;

    for(int i = 0 ; i < V ; i++){
        int minVertex = getMinVextex(dist, visited, V);
        visited[minVertex] = true;

        for(int j = 0 ; j < V ; j++)
            if(g[minVertex][j] != 0)
                dist[j] = min(dist[j],dist[minVertex] + g[minVertex][j]);
    }

    return dist;
}




































