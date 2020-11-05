#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void firstIndexOf(vector<int> &arr, int l, int r,int x, int &ans){
    if(l > r)
        return;

    int mid = l + (r - l)/2;
    if(arr[mid] == x)
        ans = mid;
    if(x <= arr[mid])
        firstIndexOf(arr, l, mid - 1, x, ans);
    else
        firstIndexOf(arr, mid + 1, r, x, ans);
}

void lastIndexOf(vector<int> &arr, int l, int r, int x, int &ans){
    if(l > r)
        return;

    int mid = l + (r - l)/2;
    if(arr[mid] == x)
        ans = mid;
    if(x >= arr[mid])
        lastIndexOf(arr, mid + 1, r, x, ans);
    else
        lastIndexOf(arr, l, mid - 1, x, ans);
}

void firstAndLastIndexOf(vector<int> &arr, int x){
    int firstIndex=-1;
    firstIndexOf(arr, 0, arr.size(), x, firstIndex);
    if(firstIndex == -1){
        cout<<"-1"<<endl;
        return;
    }

    int lastIndex=-1;
    lastIndexOf(arr, 0, arr.size(), x, lastIndex);
    cout<<firstIndex<<" "<<lastIndex<<endl;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n,x;cin>>n>>x;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        firstAndLastIndexOf(arr, x);
    }
}
