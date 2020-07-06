#include <iostream>
#include <unordered_map>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1

long long int countSubarrWithEqualZeroAndOne(int arr[], int N){
    unordered_map<int,int> hashmap;

    for(int i = 0 ; i < N ; i++){
        if(arr[i] == 0)
            arr[i] = -1;
    }

    int running_sum = 0;
    long long int subarray_count = 0;
    for(int i = 0 ; i < N ; i++){
        running_sum += arr[i];

        if(running_sum == 0){
            subarray_count += hashmap[0] + 1;
        }else{
            subarray_count += hashmap[running_sum];
        }

        if(hashmap.find(running_sum) == hashmap.end())
            hashmap[running_sum] = 1;
        else
            hashmap[running_sum] += 1;
    }

    return subarray_count;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int n;cin>>n;
        int arr[n];
        for(int j = 0 ; j < n ; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        cout<<countSubarrWithEqualZeroAndOne(arr, n)<<endl;
    }
}
