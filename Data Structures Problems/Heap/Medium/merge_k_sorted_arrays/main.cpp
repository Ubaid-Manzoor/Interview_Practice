// { Driver Code Starts
#include<bits/stdc++.h>


#define N 105
using namespace std;

int *mergeKArrays(int arr[][N],int k);

void printArray(int arr[], int size)
{
for (int i=0; i < size; i++)
    cout << arr[i] << " ";
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        int arr[N][N];
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++)
            {
                cin>>arr[i][j];
            }
        }
    int *output = mergeKArrays(arr, k);
    printArray(output, k*k);
    cout<<endl;
}
    return 0;
}// } Driver Code Ends


// your task is tocomplete this function
// function should return an pointer to output array int*
// of size k*k

typedef pair<int,pair<int,int>> pOfp;
int *mergeKArrays(int arr[][N], int k){
    priority_queue<pOfp, vector<pOfp>, greater<pOfp> > minheap;
    int *sorted_arr = new int[k*k];


    for(int i = 0 ;i < k ; i++)
        minheap.push(make_pair(arr[i][0], make_pair(i, 0)));

    for(int index = 0 ; index < k*k ; index++){
        pOfp top = minheap.top();
        sorted_arr[index] = top.first;
        int row = top.second.first;
        int col = top.second.second + 1;
        minheap.pop();

        if(col < k)
            minheap.push(make_pair(arr[row][col], make_pair(row, col)));
    }

    return sorted_arr;
}




