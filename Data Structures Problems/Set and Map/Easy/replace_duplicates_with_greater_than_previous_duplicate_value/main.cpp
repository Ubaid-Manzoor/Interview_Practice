#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void replaceElements(int arr[], int n){
    unordered_set<int> hashset;

    for(int i = 0 ; i < n ; i++ ){
        if(hashset.count(arr[i]) == 1){
            for(int candidate = arr[i] + 1; candidate < INT_MAX; candidate++){
                if(hashset.count(candidate) == 0){
                    arr[i] = candidate;
                    break;
                }
            }
        }
        hashset.insert(arr[i]);
    }
}

int main()
{
    int arr[] = { 10, 2, 5, 7, 100, 100, 6 ,7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    replaceElements(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
