#include <iostream>
#include <vector>

using namespace std;

int countRotation(vector<int> arr, int low, int high){
//    cout<<low<<" "<<high<<endl;
    if(low > high)
        return 0;
    int mid = (low + high)/2;

    if(arr[mid] > arr[mid + 1])
        return mid + 1;
    if(mid > low and arr[mid - 1] > arr[mid])
        return mid;

    if(arr[mid] < arr[high])
        return countRotation(arr, low, mid - 1);
    return countRotation(arr, mid + 1, high);
}

int main(){
    vector<int> arr = {7,2,3,4,5,6};
    cout<<countRotation(arr, 0, arr.size() - 1)<<endl;
}

// Binary Search based C++ program to find number
// of rotations in a sorted and rotated array.
//#include<bits/stdc++.h>
//using namespace std;

//// Returns count of rotations for an array which
//// is first sorted in ascending order, then rotated
//int countRotations(int arr[], int low, int high)
//{
//    cout<<low<<" "<<high<<endl;
//    // This condition is needed to handle the case
//    // when the array is not rotated at all
//    if (high < low)
//        return 0;

//    // If there is only one element left
////    if (high == low)
////        return low;

//    // Find mid
//    int mid = low + (high - low)/2; /*(low + high)/2;*/

//    // Check if element (mid+1) is minimum element.
//    // Consider the cases like {3, 4, 5, 1, 2}
//    if (arr[mid+1] < arr[mid])
//       return (mid+1);

//    // Check if mid itself is minimum element
//    if (mid > low && arr[mid] < arr[mid - 1])
//       return mid;

//    // Decide whether we need to go to left half or
//    // right half
//    if (arr[high] > arr[mid])
//       return countRotations(arr, low, mid-1);

//    return countRotations(arr, mid+1, high);
//}

//// Driver code
//int main()
//{
//    int arr[] = {5,4,1,2,3};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    cout << countRotations(arr, 0, n-1);
//    return 0;
//}
