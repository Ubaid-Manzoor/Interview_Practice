// CPP program to find the only repeating
// element in an array where elements are
// from 1 to n-1.
#include <bits/stdc++.h>
using namespace std;


// Using HashMap
int findRepeating(int arr[], int n) {
    unordered_set<int> hash;

    for(int i = 0 ; i < n ; i++){
        if(hash.find(arr[i]) != hash.end())
            return arr[i];

        hash.insert(arr[i]);
    }

    return -1;
}

// Using Indexing
int findRepeating_(int arr[], int n){
    for(int i = 0 ;i < n ; i++){
        int index = abs(arr[i]);
        if(arr[index] < 0)
            return index;
        arr[index] = -arr[index];
    }

    return -1;
}

// driver code
int main()
{
    int arr[] = { 9, 8, 2, 6, 1, 8, 5, 3, 4, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findRepeating_(arr, n)<<endl;
    return 0;
}
