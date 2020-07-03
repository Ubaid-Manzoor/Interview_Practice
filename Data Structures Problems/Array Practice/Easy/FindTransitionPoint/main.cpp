#include <iostream>
#include <vector>

using namespace std;

// Problem Link :- https://practice.geeksforgeeks.org/problems/find-transition-point-1587115620/1

int binary_search(int arr[], int left, int right){
    if(left == right)
        return left;

    int mid = (left + right) / 2;
    if(arr[mid] == 1){
        if(arr[mid - 1] == 0){
            return mid;
        }else{
            return binary_search(arr, left, mid-1);
        }
    }else{
        if(arr[mid + 1] == 1){
            return mid + 1;
        }else{
            return binary_search(arr, mid + 1, right);
        }
    }
}

// Function to find the transition point
int transitionPoint(int arr[], int n){
    if(arr[n-1] == 0)
        return -1;
    int answer = binary_search(arr, 0, n);
}

// Vector Version

//int binary_search(const vector<int> &arr, int left, int right){
//    if(left == right)
//        return left;

//    int mid = (left + right) / 2;
//    if(arr[mid] == 1){
//        if(arr[mid - 1] == 0){
//            return mid;
//        }else{
//            return binary_search(arr, left, mid-1);
//        }
//    }else{
//        if(arr[mid + 1] == 1){
//            return mid + 1;
//        }else{
//            return binary_search(arr, mid + 1, right);
//        }
//    }
//}

//int transition_point(vector<int> &arr){
//    if(arr.back() == 0)
//        return -1;
//    cout<<binary_search(arr, 0, arr.size())<<endl;
//}

int main()
{
    vector<int> arr={1,1,1,1,1};
    transition_point(arr);
}
