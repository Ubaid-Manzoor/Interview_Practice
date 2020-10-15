#include <bits/stdc++.h>
#include <iostream>

using namespace std;

struct coordinate{
    int x, y;
    int dis;
    coordinate(int x,int y, int dis){
        this->x = x;
        this->y = y;
        this->dis = dis;
    }
};

bool isValid(int x, int y, int boardSize){
    if(x >=0 and x < boardSize and y >= 0 and y < boardSize)
        return true;
    return false;
}

int minStepToTarget(int boardSize, int x, int y, int t_x, int t_y){
    queue<coordinate> q;
    q.emplace(coordinate(x,y,0));

    int dx[] = {-2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1 };
    int visited[boardSize][boardSize];

    for(int i = 0 ; i < boardSize ; i++)
        for(int j = 0 ; j < boardSize; j++)
            visited[i][j] = false;

    while(not q.empty()){
        coordinate C = q.front();
        q.pop();
        x = C.x;
        y = C.y;
        int dis = C.dis;
        visited[x][y] = true;

        if(x == t_x and y == t_y)
            return dis;


        for(int i = 0 ; i < 8 ; i++){
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            if(isValid(new_x, new_y, boardSize) and not visited[new_x][new_y])
                q.emplace(coordinate(new_x, new_y, dis + 1));
        }
    }
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        int x,y;cin>>x>>y; // Coordinate of the Knight
        int t_x,t_y;cin>>t_x>>t_y;
        cout<<minStepToTarget(n, x-1, y-1, t_x-1, t_y-1)<<endl;
    }
}
