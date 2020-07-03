#include <iostream>
#include <vector>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/sum-of-lengths-of-non-overlapping-subarrays/0

int sum_of_subarrays(vector<int> &arr, int k){
    int total_count = 0;

    int local_count = 0;
    bool already_seen_k =false;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] < k)
            local_count+=1;
        else if(arr[i] == k){
            already_seen_k = true;
            local_count +=1;
        }
        else if(already_seen_k){
            total_count += local_count;
            already_seen_k = false;
        }
        else
            local_count = 0;
    }

    if(already_seen_k and local_count != 0)
        return total_count + local_count;
    return total_count;
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
        int k;cin>>k;
        cout<<sum_of_subarrays(arr,k)<<endl;
    }
}
