#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long int zero_sum_subarrays(vector<int> &arr){
    unordered_map<int,int> hashmap;

    long long int running_sum = 0;
    long long int subarray_count = 0;
    for(int i = 0 ; i < arr.size(); i++){
        running_sum += arr[i];

        if(running_sum == 0)
            subarray_count++;

        if(hashmap.find(running_sum) != hashmap.end()){
            subarray_count += hashmap[running_sum];
            hashmap[running_sum] += 1;
        }
        else{
            hashmap[running_sum] = 1;
        }
    }

    return subarray_count;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int n;cin>>n;
        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            int value;cin>>value;
            arr[j] = value;
        }

        cout<<zero_sum_subarrays(arr)<<endl;
    }
}
