#include <iostream>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/peak-element/1

// Time Complexity O(logn)
int binary_search(int arr[], int left, int right){
    if(left == right)
        return left;

    int mid = (left + right) / 2;
    if(arr[mid-1] <= arr[mid]){
        if(arr[mid] < arr[mid+1])
            binary_search(arr, mid + 1, right);
        else
            return mid;
    }else
        binary_search(arr, left, mid - 1);
}

int peakElement(int arr[], int n){
    return binary_search(arr, 0, n-1);
}

int main()
{
    int arr[] = {1,2,3};
    int n = 3;
    cout<<peakElement(arr,n)<<endl;
}
