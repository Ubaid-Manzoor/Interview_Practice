#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct coordinates{
    int x,y;
    int time;
    coordinates(int x_,int y_,int time_){
        x = x_;y = y_;time = time_;
    }
};


bool checkIfValid(coordinates C, int row_limit, int col_limit){
    return C.x >= 0 and C.x < row_limit and C.y >= 0 and C.y < col_limit;
}

int timeToRotte(vector<vector<int>> box){
    queue<coordinates> q;

    int rows = box.size();
    int cols = box[0].size();

    int fresh_oranges=0;
    for(int r=0 ; r < rows; r++){

        for(int c = 0 ; c < cols; c++){
            if(box[r][c] == 2)
                q.emplace(coordinates(r,c,0));
            if(box[r][c] == 1)
                fresh_oranges++;
        }
    }

    int min_time=0;
    while(not q.empty()){
        coordinates current = q.front();q.pop();
        coordinates top = coordinates(current.x - 1, current.y, current.time);
        coordinates right = coordinates(current.x, current.y + 1, current.time);
        coordinates bottom = coordinates(current.x + 1, current.y, current.time);
        coordinates left = coordinates(current.x, current.y - 1, current.time);

        min_time = max(min_time, top.time);

        if(checkIfValid(top,rows,cols) and box[top.x][top.y] == 1){
            top.time++;q.emplace(top);box[top.x][top.y] = 2;fresh_oranges--;
        }
        if(checkIfValid(right,rows,cols) and box[right.x][right.y] == 1){
            right.time++;q.emplace(right);box[right.x][right.y] = 2;fresh_oranges--;
        }
        if(checkIfValid(bottom,rows,cols) and box[bottom.x][bottom.y] == 1){
            bottom.time++;q.emplace(bottom);box[bottom.x][bottom.y] = 2;fresh_oranges--;
        }
        if(checkIfValid(left,rows,cols) and box[left.x][left.y] == 1){
            left.time++;q.emplace(left);box[left.x][left.y] = 2;fresh_oranges--;
        }
    }


    if(fresh_oranges > 0)
        return -1;
    else
        return min_time;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int r,c;cin>>r>>c;

        vector<vector<int>> box(r,vector<int>(c));
        for(int row = 0 ; row < r ; row++){
            for(int col = 0 ; col < c ; col++){
                cin>>box[row][col];
            }
        }

        cout<<timeToRotte(box)<<endl;
    }
}
