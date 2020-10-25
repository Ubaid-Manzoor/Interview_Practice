#include<bits/stdc++.h>
using namespace std;

struct GraphNode
{
    int val;

    //A neighbour vector which contains addresses to
    //all the neighbours of a GraphNode
    vector<GraphNode*> neighbours;

    GraphNode(int value){
        this->val = value;
    }
};

// A function which clones a Graph and
// returns the address to the cloned
// src node
GraphNode *cloneGraph(GraphNode *src) {
    queue<GraphNode*> q;
    unordered_map<int, GraphNode*> visited;
    GraphNode* sourceNode = new GraphNode(src->val);

    q.emplace(src);
    visited[src->val] = sourceNode;
    while(not q.empty()){
        GraphNode* original_v = q.front();q.pop();
        GraphNode* clone_v = visited[original_v->val];

        for(GraphNode* neighNode: original_v->neighbours){
            if(not visited.count(neighNode->val)){
                GraphNode* clone_neigh = new GraphNode(neighNode->val);
                clone_v->neighbours.emplace_back(clone_neigh);
                visited[neighNode->val] = clone_neigh;
                q.emplace(neighNode);
            }else
                clone_v->neighbours.emplace_back(visited[neighNode->val]);
        }
    }

    return sourceNode;
}

// Build the desired graph
GraphNode *buildGraph()
{
    /*
        Note : All the edges are Undirected
        Given Graph:
        1--2
        | |
        4--3
    */
    GraphNode *node1 = new GraphNode(1);
//    node1->val = 1;
    GraphNode *node2 = new GraphNode(2);
//    node2->val = 2;
    GraphNode *node3 = new GraphNode(3);
//    node3->val = 3;
    GraphNode *node4 = new GraphNode(4);
//    node4->val = 4;
    vector<GraphNode *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbours = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbours = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbours = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbours = v;
    return node1;
}

void bfs(GraphNode *src)
{
    map<GraphNode*, bool> visit;
    queue<GraphNode*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        GraphNode *u = q.front();
        cout << "Value of Node " << u->val << "\n";
        cout << "Address of Node " <<u << "\n";
        q.pop();
        vector<GraphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (!visit[v[i]])
            {
                visit[v[i]] = true;
//                cout<<endl<<"child : "<<v[i]->val<<endl;
                q.push(v[i]);
            }
        }
    }
    cout << endl;
}

// A simple bfs traversal of a graph to
// check for proper cloning of the graph

// Driver program to test above function
int main()
{
    GraphNode *src = buildGraph();
    cout << "BFS Traversal before cloning\n";
    bfs(src);
    GraphNode *newsrc = cloneGraph(src);
    cout << "BFS Traversal after cloning\n";
    bfs(newsrc);
    return 0;
}
