// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

#define MAX 5
vector<string> printPath(int m[MAX][MAX], int n);

// Position this line where user code will be pasted.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int m[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }

        vector<string> result = printPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}// } Driver Code Ends


// User function template for C++

// m is the given matrix and n is the order of matrix
// MAX is the upper limit of N ie 5

void printPathUtil(int m[MAX][MAX], int n, vector<string> &paths, int row=0, int col=0, string path="") {
    if(row == n-1 and col == n-1){
        paths.push_back(path);
        return;
    }

    // Up
    if((row - 1) >= 0 and m[row - 1][col] != 0){
        m[row][col] = 0;
        printPathUtil(m, n, paths, row - 1, col, path + "U");
        m[row][col] = 1;
    }

    // Down
    if((row + 1) < n and m[row + 1][col] != 0 and path.back() != 'U'){
        m[row][col] = 0;
        printPathUtil(m, n, paths, row + 1, col, path + "D");
        m[row][col] = 1;
    }
    // Left
    if((col - 1) >= 0 and m[row][col - 1] != 0 and path.back() != 'R'){
        m[row][col] = 0;
        printPathUtil(m, n, paths, row , col - 1, path + "L");
        m[row][col] = 1;
    }
    // Right
    if((col + 1) < n and m[row][col + 1] != 0 and path.back() != 'L'){
        m[row][col] = 0;
        printPathUtil(m, n, paths, row, col + 1, path + "R");
        m[row][col] = 1;
    }


}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string> paths;
    if(m[0][0] == 0)
        return paths;
    printPathUtil(m, n, paths);
    sort(paths.begin(), paths.end());
    return paths;
}






