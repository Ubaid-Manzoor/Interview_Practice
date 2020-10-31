#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int pivotIndex(vector<int> &arr, int l, int r){
    if(l > r)
        return 0;

    int mid = l + (r - l)/2;
    if(arr[mid] > arr[mid+1])
        return mid;
    if(arr[mid] < arr[0])
        return pivotIndex(arr, l, mid - 1);
    else
        return pivotIndex(arr, mid + 1, r);
}

int binarySearch(vector<int> &arr, int l, int r, int x){
    if(l > r)
        return -1;
    int mid = l + (r - l)/2;

    if(arr[mid] == x)
        return mid;

    if(x < arr[mid])
        return binarySearch(arr, l, mid - 1, x);
    else
        return binarySearch(arr, mid + 1, r, x);
}

int searchFor(vector<int> &arr, int x){
    int pivot = pivotIndex(arr, 0, arr.size()-1);

    int index;
    index = binarySearch(arr, 0, pivot, x);
    if(index != -1)
        return index;
    index = binarySearch(arr, pivot+1, arr.size()-1, x);
    return index;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        int valueToFind;cin>>valueToFind;
        cout<<searchFor(arr, valueToFind)<<endl;
    }
}
