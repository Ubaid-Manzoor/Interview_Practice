#include <iostream>

using namespace std;

void insertionSortRecursive(int arr[], int n){
    if(n <= 1)
        return;

    insertionSortRecursive(arr, n-1);

    while(n-2 >= 0 and arr[n-2] > arr[n-1]){
        swap(arr[n-2] , arr[n-1]);
        n--;
    }
}

void printArray(int arr[], int n){
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertionSortRecursive(arr, n);
    printArray(arr, n);

    return 0;
}
