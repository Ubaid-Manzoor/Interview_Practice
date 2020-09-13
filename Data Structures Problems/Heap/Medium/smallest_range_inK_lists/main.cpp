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
pair<int,int> findSmallestRange(int arr[][N], int n, int k){
    priority_queue<>;
}
