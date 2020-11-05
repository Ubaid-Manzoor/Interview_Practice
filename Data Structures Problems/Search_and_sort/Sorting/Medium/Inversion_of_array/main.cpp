#include <bits/stdc++.h>
#include <iostream>

using namespace std;

typedef long long int ll;

void mergeAndCount(vector<int> &arr, ll l, ll m, ll r, ll &inversions){
    vector<int> left(arr.begin() + l, arr.begin() + m+1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r+1);

    int i = 0, j = 0, k = l;

    while(i < left.size() and j < right.size()){
        if(left[i] < right[j]){
            arr[k] = left[i];i++;
        }else{
            inversions += right.size() - j;
            arr[k] = right[j];j++;
        }
        k++;
    }

    while(i < left.size()){
        arr[k] = left[i];
        k++;i++;
    }

    while(j < right.size()){
        arr[k] = right[j];
        k++;j++;
    }
}

void mergeSort(vector<int> &arr, ll l, ll r, ll &inversions){
    if(l < r){
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid, inversions);
        mergeSort(arr, mid + 1, r, inversions);
        mergeAndCount(arr, l, mid, r, inversions);
    }
}


ll countInversions(vector<int> &arr){
    ll inversions=0;
    mergeSort(arr, 0, arr.size()-1, inversions);
    return inversions;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        ll n;cin>>n;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        cout<< countInversions(arr) <<endl;
    }
}
