#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isValid(vector<vector<int>> &board, int row, int col){
    // left row positions
    int tempCol = col-1;
    while(tempCol >= 0){
        if(board[row][tempCol] == 1)
            return false;
        tempCol--;
    }

    // up cols positions
    int tempRow = row-1;
    while(tempRow >= 0){
        if(board[tempRow][col] == 1)
            return false;
        tempRow--;
    }

    //left top diagonal positions
    tempRow = row - 1;
    tempCol = col - 1;
    while(tempRow >= 0 and tempCol >= 0){
        if(board[tempRow][tempCol] == 1)
            return false;
        tempRow--;tempCol--;
    }

    //left bottom diagonal positions
    tempRow = row + 1;
    tempCol = col - 1;
    while(tempRow < board.size() and tempCol >= 0){
        if(board[tempRow][tempCol] == 1)
            return false;
        tempRow++;tempCol--;
    }

    return true;
}

void NQueenPositionsUtil(vector<vector<int>> &board,
                         vector<int> positions,
                         vector<vector<int>> &positionsVector,
                         int col=0){
//    cout<<"NQueenPositionsUtil("<<"board, "<<"positions, "<<"positionsVector,"<<col<<")"<<endl;
    int boardSize = board.size();
    if(positions.size() == boardSize){
        positionsVector.emplace_back(positions);
        return;
    }
    if(col >= boardSize)
        return;


    for(int row = 0 ; row < boardSize ; row++){

        if(isValid(board, row, col)){
            board[row][col] = 1;
            positions.emplace_back(row + 1);
            NQueenPositionsUtil(board, positions, positionsVector, col + 1);
            board[row][col] = 0;
            positions.pop_back();
        }
    }
}

vector<vector<int>> NQueenPositions(int boardSize){
    vector<vector<int>> positionsVector;
    vector<int> positions;
    vector<vector<int>> board(boardSize, vector<int>(boardSize));
    for(int r = 0 ; r < boardSize ; r++)
        for(int c = 0 ; c < boardSize ; c++)
            board[r][c] = 0;

    NQueenPositionsUtil(board, positions, positionsVector);
    return positionsVector;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;
        vector<vector<int>> positions = NQueenPositions(n);
        for(vector<int> v: positions){
            cout<<"[";
            for(int i = 0 ; i < v.size() ; i++){
                cout<<v[i];
                if(i < v.size()-1)
                    cout<<" ";
            }
            cout<<"]";
            cout<<" ";
        }
    }
}
