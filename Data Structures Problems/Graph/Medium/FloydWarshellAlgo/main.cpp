#include <bits/stdc++.h>
#include <iostream>

using namespace std;
// #define INF 10000000

void printMatrix(const vector<vector<int>> &matrix){
    int V = matrix.size();
    for(int r = 0 ; r < V ; r++){
        for(int c = 0 ; c < V ; c++){
            if(matrix[r][c] == 10000000)
                cout<<"INF"<<" ";
            else
                cout<<matrix[r][c]<<" ";
        }
        cout<<endl;
    }
}

void floydWarshell(vector<vector<int>> matrix){
    int V = matrix.size();

    for(int v = 0 ; v < V ; v++){

        // Choose vertex v
        for(int r = 0 ; r < V ; r++){
            for(int c = 0 ; c < V ; c++){
                if(matrix[r][v] + matrix[v][c] < matrix[r][c])
                    matrix[r][c] = matrix[r][v] + matrix[v][c];
            }
        }
    }

    printMatrix(matrix);
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int V;cin>>V;

        vector<vector<int>> matrix(V, vector<int>(V));
        for(int r = 0 ; r < V ; r++){
            for(int c = 0 ; c < V ; c++){
                cin>>matrix[r][c];
            }
        }

        floydWarshell(matrix);
    }
}
