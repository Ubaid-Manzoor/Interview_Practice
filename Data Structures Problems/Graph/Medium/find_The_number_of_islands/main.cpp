// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}// } Driver Code Ends


/*you are required to complete this method*/

/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
struct coordinate{
    int x,y;
    coordinate(int x, int y){
        this->x = x;
        this->y = y;
    }
};

bool isValid(int x, int y, int N, int M, vector<int> A[]){
    if(x >= 0 and x < N and y >= 0 and y < M and A[x][y])
        return true;
    return false;
}

void bfs(vector<int> A[], int i, int j, int N, int M){
    queue<coordinate> q;

    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {-1, 0, 1,-1, 1, -1, 0, 1};
    q.emplace(coordinate(i,j));
    while(not q.empty()){
        coordinate C = q.front();
        q.pop();

        int x = C.x;
        int y = C.y;
        A[x][y] = 0;
        for(int k = 0 ; k < 8 ; k++){
            int new_x = x + dx[k];
            int new_y = y + dy[k];
            if(isValid(new_x, new_y, N, M, A)){
                q.emplace(coordinate(new_x, new_y));
            }
        }
    }
}

void dfs(vector<int> A[], int x, int y, int N, int M){
    if(isValid(x,y, N, M, A)){
        A[x][y] = 0;
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {-1, 0, 1,-1, 1, -1, 0, 1};
        for(int i = 0 ; i < 8 ; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            dfs(A, new_x, new_y, N, M);
        }
    }

}

int findIslands(vector<int> A[], int N, int M) {
    int islandCount=0;
    for(int i = 0 ; i < N; i++){
        for(int j = 0 ; j < M ; j++){
            if(A[i][j]){
                islandCount++;
                dfs(A, i, j, N, M);
            }
        }
    }
    return islandCount;
}
