#include <iostream>
#include <vector>
#include <algorithm>
//#include <utility>

using namespace std;

// Problem Link : https://www.geeksforgeeks.org/rearrange-array-arri/

void printVec(const vector<int> &arr){
    for(const int v:arr)
        cout<<v<<" ";
    cout<<endl;
}

// Time Complexity O(n)
// Space Complexity O(1)
int rearrange(vector<int> &arr){
    for(int i = 0 ; i < arr.size();i++){
        if(arr[i] != -1)
            iter_swap(arr.begin() + i, arr.begin() + arr[i]);
    }
}

int main(){
//    vector<int> arr={-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    vector<int> arr={19, 7, 0, 3, 18, 15, 12, 6, 1, 8,11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
    rearrange(arr);
    printVec(arr);
}
