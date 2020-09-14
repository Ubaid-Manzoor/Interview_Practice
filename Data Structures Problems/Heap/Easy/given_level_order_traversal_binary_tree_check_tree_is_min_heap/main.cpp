#include <iostream>
#include <vector>

using namespace std;


// Using Recursion

bool isMinHeapUtil(vector<int> &arr, int index){
    int n = arr.size();
    if(index >= n)
        return true;

    int l = 2 * index + 1;
    int r = 2 * index + 2;

    if( (l < n and arr[l] < arr[index]) or (r < n and arr[r] < arr[index]) )
        return false;

    return isMinHeapUtil(arr, l) and isMinHeapUtil(arr, r);
}

bool isMinHeap_r(vector<int> arr){
    return isMinHeapUtil(arr, 0);
}


// WithOut Recursion

bool isMinHeap(vector<int> arr, int n){
    for(int i = (arr.size()-2)/2 ; i >= 0 ; i-- ){
        if(arr[2 * i + 1] < arr[i]){
            return false;
        }
        if(2 * i + 2 < n and arr[2 * i + 2] < arr[i]){
            return false;
        }
    }

    return true;
}

int main()
{
    vector<int> arr = {10, 15, 14, 25, 30};
//    vector<int> arr = {30, 56, 22, 49, 30, 51, 2, 67};
//    vector<int> arr = {30, 56, 31, 57, 58, 100, 200, 56};
    int n = arr.size();
    if  (isMinHeap(arr, n))
        cout << "True"<<endl;
    else
        cout << "False"<<endl;
    return 0;
}
