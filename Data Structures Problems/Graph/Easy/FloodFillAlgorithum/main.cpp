#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// void dfs(){

// }

bool isValid(int x, int y, int N, int M,const vector<vector<int>> &screen, int colorToR){
    if(x >= 0 and x < N and y >=0 and y < M and screen[x][y] == colorToR)
        return true;
    return false;
}

void floodFill(vector<vector<int>> &screen, int N, int M, int x, int y, int newColor, int colorToR){
    if(screen[x][y] == colorToR)
        screen[x][y] = newColor;

    int new_x = x + 1;
    int new_y = y;
    if(isValid(new_x, new_y, N, M, screen, colorToR))
        floodFill(screen, N, M, new_x, new_y, newColor, colorToR);

    new_x = x - 1;
    new_y = y;
    if(isValid(new_x, new_y, N, M, screen, colorToR))
        floodFill(screen, N, M, new_x, new_y, newColor, colorToR);

    new_x = x;
    new_y = y + 1;
    if(isValid(new_x, new_y, N, M, screen, colorToR))
        floodFill(screen, N, M, new_x, new_y, newColor, colorToR);

    new_x = x;
    new_y = y - 1;
    if(isValid(new_x, new_y, N, M, screen, colorToR))
        floodFill(screen, N, M, new_x, new_y, newColor, colorToR);
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int N,M;cin>>N>>M;

        vector<vector<int>> arr(N, vector<int>(M));
        for(int n = 0 ; n < N ; n++){
            for(int m = 0 ; m < M ; m++){
                cin>>arr[n][m];
            }
        }
        int x,y; cin>>x>>y;
        int newColor;cin>>newColor;
        int colorToReplace = arr[x][y];

        floodFill(arr, N, M, x, y, newColor, colorToReplace);
        for(int n = 0 ; n < N ; n++){
            for(int m = 0 ; m < M ; m++){
                cout<<arr[n][m]<<" ";
            }
        }
        cout<<endl;

    }
}
