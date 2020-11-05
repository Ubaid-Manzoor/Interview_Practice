#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lowerBoundUtil(int arr[], int l, int r, int x){
    if(l > r)
        return l;
    int mid = l + (r - l) / 2;

    if(arr[mid] == x)
        return mid;
    if(arr[mid] > x)
        return lowerBoundUtil(arr, l, mid - 1, x);
    else
        return lowerBoundUtil(arr, mid + 1, r, x);

}

int lowerBound(int arr[], int N, int x){
    return lowerBoundUtil(arr, 0, N-1, x);
}

int upperBoundUtil(int arr[], int l, int r, int x){
    if(l > r)
        return l;

    int mid = l + (r - l)/2;

    if(x >= arr[mid])
        return upperBoundUtil(arr, mid + 1, r, x);
    else
        return upperBoundUtil(arr, l, mid - 1, x);
}

int upperBound(int arr[], int N, int x){
    return upperBoundUtil(arr, 0, N-1, x);
}

int main()
{
    // Given array
    int arr[] = { 4, 6, 10, 12, 18, 20 };
    int N = sizeof(arr) / sizeof(arr[0]);

    // Element whose lower bound and
    // upper bound to be found
    int X = 6;

    for(int i = 0 ; i < 23 ; i++){
        if(upper_bound(arr, arr + N, i) - arr == upperBound(arr, N, i))
            cout<<"passed for "<<i<<endl;
        else
            cout<<"failed for "<<i<<endl;
    }

    // Function Call
//    printBound(arr, N, X);
    return 0;
}
