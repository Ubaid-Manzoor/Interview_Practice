// { Driver Code Starts
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        rangee = findSmallestRange(arr, n, k);
        cout<<rangee.first<<" "<<rangee.second<<"\n";
    }
    return 0;
}

// } Driver Code Ends


// you are required to complete this function
// function should print the required range
#include <queue>
typedef pair<int,pair<int,int>> pOp;
pair<int,int> findSmallestRange(int arr[][N], int n, int k){
    priority_queue<pOp, vector<pOp>, greater<pOp>> minheap;

    int max=INT_MIN;

    for(int i = 0 ;i < k ; i++){
        if(arr[i][0] > max)
            max = arr[i][0];
        minheap.push(make_pair(arr[i][0], make_pair(i,0)));
    }

    int minRangeMin = minheap.top().first;
    int minRangeMax = max;
    int minRange = minRangeMax - minRangeMin;
    int min, range;

    while(true){
        pOp top = minheap.top();
        minheap.pop();

        min = top.first;
        range = max - min;
        if(range < minRange){
            minRangeMin = min;
            minRangeMax = max;
            minRange = range;
        }




        int row = top.second.first;
        int col = top.second.second + 1;

        if(col < k){
            minheap.push(make_pair(arr[row][col], make_pair(row,col)));
        }else
            break;

        if(arr[row][col] > max)
            max = arr[row][col];
    }

    return make_pair(minRangeMin, minRangeMax);
}










//1
//5 3
//1 3 5 7 9
//0 2 4 6 8
//2 3 5 7 11








