#include <iostream>
#include <vector>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/count-the-zeros/0

void printVec(vector<int> &arr){
    for(int v:arr){
        cout<<v<<" ";
    }
    cout<<endl;
}


int binary_search(const vector<int> &arr, int left, int right){
    cout<<left<<" "<<right<<endl;
    if(left > right)
        return left - 1;

    int mid = (left + right) / 2;

    if(arr[mid] == 1 and arr[mid + 1] == 0)
        return mid;
    if(arr[mid] == 1){
        return binary_search(arr, mid + 1, right);
    }else{
        return binary_search(arr, left, mid - 1);
    }
}

// Time Complexity O(logn)
int count_zeros(const vector<int> &arr){
    if(arr.back() == 1)
        return 0;

    int transition_point = binary_search(arr,0, arr.size() - 1);
    return arr.size() - transition_point - 1;
}

int main(){
    int testcase;
    cin>>testcase;

    for(int tc = 0 ; tc < testcase ; tc++ ){
        int N;cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < arr.size() ; i++){
            int value;cin>>value;
            arr[i] = value;
        }
        printVec(arr);
        cout<<count_zeros(arr)<<endl;
    }
}


