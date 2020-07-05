#include <iostream>
#include <vector>

using namespace std;

int submatrix_sum(vector<int> &matrix, int x1, int y1, int x2, int y2, int rows, int cols){
    int sum=0;
    for(int k = 0,i_row=0,j_cols=0 ; k < (rows+1) * (cols+1); k++,j_cols++){
        if(k != 0 and k % (cols+1) == 0){
            j_cols=0;
            i_row++;
        }

        if(x1 <= i_row and i_row <= x2 and y1 <= j_cols and j_cols <= y2){
            sum += matrix[k];
        }
    }
    return sum;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int rows,cols;
        cin>>rows>>cols;
        vector<int> matrix(rows*cols);
        for(int j = 0 ; j < rows * cols; j++){
            int value;cin>>value;
            matrix[j] = value;
        }

        int X1,X2,Y1,Y2;
        cin>>X1>>Y1>>X2>>Y2;
        cout<<submatrix_sum(matrix,X1-1,Y1-1,X2-1,Y2-1,rows-1,cols-1)<<endl;
    }
}
