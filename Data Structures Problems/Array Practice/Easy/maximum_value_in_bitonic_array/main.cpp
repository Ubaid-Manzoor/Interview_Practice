#include <iostream>
#include <vector>

using namespace std;

// Problem Link : https://practice.geeksforgeeks.org/problems/maximum-value-in-a-bitonic-array/0

int binary_search(const vector<int> &arr, int left, int right){
    if(left == right)
        return arr[left];

    int mid = (left + right)/2;
    if(arr[mid] < arr[mid + 1]){
        binary_search(arr, mid + 1, right);
    }
    else{
        if(arr[mid - 1] < arr[mid])
            return arr[mid];
        else
            binary_search(arr, left, mid-1);
    }
}

int max_value(vector<int> &arr){
    return binary_search(arr, 0, arr.size()-1);
}

int main() {
    //code
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int N;cin>>N;
        vector<int> arr(N);
        for(int j = 0 ; j < N; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        cout<<max_value(arr)<<endl;
    }
}
