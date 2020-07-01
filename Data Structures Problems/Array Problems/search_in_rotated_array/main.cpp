#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int> &arr, int low, int high, int key){
    int mid = (low + high) / 2;
    if(arr[mid] == key)
        return mid;
    else if(low == high)
        return -1;

    if(arr[mid] <= arr[high]){ // Means right part is sorted
        if(key > arr[mid] and key <= arr[high])
            return search(arr, mid + 1, high, key);
        return search(arr, low, mid - 1, key);
    }

    // If the above condition fails that mean left part is sorted
    if(key >= arr[low] and key < arr[mid])
        return search(arr, low, mid - 1, key);
    return search(arr, mid + 1, high, key);
}

int main(){
    vector<int> arr = {4,5,6,7,8,9,1,2,3}; // Rotated Array
//    int key = 6;
    for(int key = 1; key < 10 ; key++)
       cout<<search(arr, 0, arr.size() - 1, key)<<endl;
}
