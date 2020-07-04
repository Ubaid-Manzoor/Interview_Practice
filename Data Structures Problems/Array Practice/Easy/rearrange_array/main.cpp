#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/rearrange-an-array-such-that-arri-i/0


void printVec(const vector<int> &arr){
    for(const int v:arr)
        cout<<v<<" ";
    cout<<endl;
}


// Time Complexity is O(n)
// Space Complexity is O(1)
void rearrange(vector<int> &arr, int swap_index=0){
    if(swap_index >= arr.size())
        return;
    if(arr[swap_index] != -1 and swap_index != arr[swap_index]){
        iter_swap(arr.begin()+swap_index, arr.begin()+arr[swap_index]);
        rearrange(arr, swap_index);
    }
    else
        rearrange(arr, swap_index + 1);
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int N;cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            int value;cin>>value;
            arr[i] = value;
        }
        rearrange(arr);
        printVec(arr);
    }
}
