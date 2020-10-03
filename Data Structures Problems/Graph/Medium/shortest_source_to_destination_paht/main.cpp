#include <bits/stdc++.h>
#include <iostream>


using namespace std;

void addToQueueIfValid(int x, int y, vector<vector<int>> matrix, queue<pair<int,int>> &q,int dis, unordered_map<int,int> &distances, unordered_set<int> &visited){
    int rows = matrix.size();
    int cols = matrix[0].size();

    if(visited.count(x*cols+y) == 1)
        return;

    if(x >= 0 and x < rows and y >= 0 and y < cols and matrix[x][y] == 1){
        if(distances.count(x*cols+y) == 0)
            distances[x*cols+y] = dis + 1;
        else
            distances[x*cols+y] = min(distances[x*cols+y], dis + 1);
        q.emplace(make_pair(x,y));
    }
}

int shortestDis(vector<vector<int>> matrix, int x, int y){
    unordered_map<int,int> distances;
    queue<pair<int,int>> q;
    unordered_set<int> visited;
    int cols = matrix[0].size();

    if(matrix[0][0] != 0)
        q.emplace(make_pair(0,0));
    distances[0] = 0;

    while(not q.empty()){
        pair<int,int> p = q.front();q.pop();
        int c_x = p.first;
        int c_y = p.second;
        int dis = distances[c_x*cols+c_y];

        visited.emplace(c_x*cols + c_y);
        addToQueueIfValid(c_x-1,c_y, matrix, q, dis, distances, visited);
        addToQueueIfValid(c_x+1,c_y, matrix, q, dis, distances, visited);
        addToQueueIfValid(c_x,c_y-1, matrix, q, dis, distances, visited);
        addToQueueIfValid(c_x,c_y+1, matrix, q, dis, distances, visited);
    }

    if(visited.count(x*cols+y) == 0)
        return -1;
    return distances[x*cols+y];
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int r,c;cin>>r>>c;

        vector<vector<int>> matrix(r, vector<int> (c));

        for(int row = 0 ; row < r ; row++){
            for(int col = 0 ; col < c ; col++){
                cin>>matrix[row][col];
            }
        }

        int x,y;cin>>x>>y;

        cout<<shortestDis(matrix, x, y)<<endl;
    }
}
