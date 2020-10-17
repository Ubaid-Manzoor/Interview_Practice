// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, int E, vector<vector<int>> &graph);
// Driver code

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int> > graph(V, vector<int>(V, INT_MAX));
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            graph[u][v] = w;
            graph[v][u] = w;
        }

        cout << spanningTree(V, E, graph) << endl;
    }
    return 0;
}
// } Driver Code Ends


// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX


struct edge{
    int s,e,w;
    edge(int s, int e, int w){
        this->s = s;
        this->e = e;
        this->w = w;
    }
};

void FillEdges(vector<vector<int>> &graph, vector<edge> &Edges){
    int s = graph.size();

    for(int i = 0 ; i < s ; i++)
        for(int j = 0 ; j < i ; j++)
            if(graph[i][j] != INT_MAX )
                Edges.emplace_back(edge(i,j, graph[i][j]));
}

bool compare(edge e1, edge e2){
    return e1.w < e2.w;
}

/******************* USING KRUSKAL ALGORITHUM WITH NAVIE UNION FIND  ****************************/

int find_(int parent[], int v){
    if(parent[v] == -1)
        return v;
    return find_(parent, parent[v]);
}

void union__(int parent[], int s, int e){
    int parentOfs = find_(parent, s);
    int parentOfe = find_(parent, e);

    if(parentOfs != parentOfe){
        parent[parentOfs] = parentOfe;
    }
}

int spanningTree_(int V, int E, vector<vector<int>> &graph) {
    // Preprocessing
    vector<edge> Edges;
    FillEdges(graph, Edges);
    // Done

    sort(Edges.begin(), Edges.end(), compare);
    int parent[V];
    for(int i = 0 ; i < V ; i++)
        parent[i] = -1;

    int totalWeight=0;
    for(edge e:Edges){
        int parentOfs = find_(parent, e.s);
        int parentOfe = find_(parent, e.e);
        if(parentOfs != parentOfe){
            totalWeight += e.w;
            union__(parent, e.s, e.e);
        }
    }

    return totalWeight;
}

/******************* USING KRUSKAL ALGORITHUM END  ****************************/


/******************* USING KRUSKAL ALGORITHUM USING OPTIMIZED UNION FIND  ****************************/

struct node{
    int parent;
    int rank;
};

int find(node subsets[], int v){
    if(subsets[v].parent != v)
        subsets[v].parent = find(subsets, subsets[v].parent);
    return subsets[v].parent ;
}

int union_(node subsets[], int s, int e){
    int rootS = find(subsets, s);
    int rootE = find(subsets, e);

    if(subsets[rootS].rank == subsets[rootE].rank){
        subsets[rootS].rank++;
        subsets[rootE].parent = rootS;
    }else if(subsets[rootS].rank < subsets[rootE].rank)
        subsets[rootS].parent = rootE;
    else
        subsets[rootE].parent = rootS;
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
    // Preprocessing
    vector<edge> Edges;
    FillEdges(graph, Edges);
    // Done
    sort(Edges.begin(), Edges.end(), compare);

    node subsets[V];
    for(int i = 0 ; i < V ; i++)
        subsets[i].parent = i,subsets[i].rank = 0;

    int totalWeight=0;
    for(edge E:Edges){
        if(find(subsets, E.s) != find(subsets, E.e)){
            totalWeight += E.w;
            union_(subsets, E.s, E.e);
        }
    }

    return totalWeight;
}

/******************* USING KRUSKAL ALGORITHUM USING OPTIMIZED UNION FIND  END****************************/

























