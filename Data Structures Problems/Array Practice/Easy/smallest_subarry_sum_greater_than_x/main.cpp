#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Problem Link : https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0

// Time Complexity O(n)
// Space Complexity O(1)
int smallest_subarray(vector<int> &arr, int sum){

    int current_subarray_size = numeric_limits<int>::max();
    int current_subarray_sum = 0;
    for(int left = 0 ,right=-1; right < int(arr.size());){
        if(current_subarray_sum <= sum ){
            right++;
            current_subarray_sum += arr[right];
        }else if(current_subarray_sum - arr[left] > sum){
            current_subarray_sum -= arr[left];
            left++;
        }else{
            current_subarray_size = min(current_subarray_size,right - left + 1);
            current_subarray_sum -= arr[left];
            left++;
        }
    }

    return current_subarray_size;
}


int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int N,sum;
        cin>>N>>sum;
        vector<int> arr(N);
        for(int j =0 ; j < N ; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        cout<<smallest_subarray(arr,sum)<<endl;
    }
}




