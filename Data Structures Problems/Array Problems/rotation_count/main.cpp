#include <iostream>
#include <vector>

using namespace std;

int countRotation(vector<int> arr, int low, int high){
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
