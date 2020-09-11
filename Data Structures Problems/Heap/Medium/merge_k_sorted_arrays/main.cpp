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
int *mergeKArrays(int arr[][N], int k){
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> minheap;
    int *sorted_arr = new int[k*k];

    for(int i = 0 ;i < k ; i++)
        minheap.push(make_tuple(arr[i][0], i, 0));

    int index=0;
    while(not minheap.empty()){
        sorted_arr[index] = get<0>(minheap.top());index++;
        int row = get<1>(minheap.top());
        int col = get<2>(minheap.top()) + 1;
        minheap.pop();

        if(col < k)
            minheap.push(make_tuple(arr[row][col], row, col));
    }

    return sorted_arr;
}




