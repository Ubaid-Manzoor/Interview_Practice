#include <bits/stdc++.h>
using namespace std;

void replaceElements(int arr[], int n) {
    int mx = *max_element(arr, arr+n)+1;

    unordered_set<int> hashset;

    for(int i = 0 ; i < n ; i++){

        if(hashset.count(arr[i]) == 1){
            arr[i] = mx;
            mx++;
        }else
            hashset.insert(arr[i]);
    }
}

// Driver code
int main()
{
//    int arr[] = { 1, 3, 4, 5, 3 };
//    int arr[] = {1, 3, 4, 4, 5, 3};
    int arr[] = {1,2,2,2,2,4,5,6,6,6,7,7,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    replaceElements(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
