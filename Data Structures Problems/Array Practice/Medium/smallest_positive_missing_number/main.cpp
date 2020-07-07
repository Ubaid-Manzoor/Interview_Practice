#include <iostream>
#include <cmath>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1

void printVector(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int missingNumber(int arr[], int n){

    for(int i = 0 ; i < n ; i++){
        if(arr[i] <= 0)
            arr[i] = n + 1;
    }

    for(int i = 0 ; i < n ;i++){
        if(abs(arr[i]) <= n and arr[abs(arr[i]) - 1] > 0){
            arr[abs(arr[i]) - 1] = -1 * arr[abs(arr[i]) - 1];
        }
    }

    for(int i = 0 ; i < n ; i++){
        if(arr[i] > 0)
            return i + 1;
    }
    return n + 1;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        cout<<missingNumber(arr, n)<<endl;
    }
    return 0;
}
