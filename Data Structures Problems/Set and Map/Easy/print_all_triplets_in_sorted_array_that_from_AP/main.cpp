#include <bits/stdc++.h>
using namespace std;

// Function to print all triplets in
// given sorted array that forms AP
void printAllAPTriplets(int arr[], int n){
    unordered_set<int> hashset;

    for(int i = 0 ;i < n ;i++)
        hashset.emplace(arr[i]);

    for(int i = 0 ; i < n ; i++){
        int a=arr[i];
        for(int j = i+1 ; j < n ; j++){
            int b = arr[j];
            int c = (b - a) + b;
            if(hashset.count(c) == 1)
                cout<<a<<" "<<b<<" "<<c<<endl;
        }
    }

}

// Driver code
int main()
{
    int arr[] = { 2, 6, 9, 12, 17,
                 22, 31, 32, 35, 42 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printAllAPTriplets(arr, n);
    return 0;
}
