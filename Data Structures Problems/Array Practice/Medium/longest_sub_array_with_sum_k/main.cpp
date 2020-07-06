#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longest_subarray(vector<int> &arr, int required_sum){
    unordered_map<int,int> hashmap;

    int running_sum=0;
    int longest_subarr = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        running_sum += arr[i];

        if(required_sum == running_sum)
            longest_subarr = i + 1;

        if(hashmap.find(running_sum) == hashmap.end())
            hashmap[running_sum] = i;

//        cout<<"required_sum :: "<<required_sum<<endl;
//        cout<<"we need :: "<<running_sum - required_sum<<endl;
        if(hashmap.find(running_sum - required_sum) != hashmap.end()){
            longest_subarr = max(longest_subarr,i - hashmap[running_sum-required_sum]);
        }

    }
    return longest_subarr;
}


int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int n;int sum;
        cin>>n>>sum;
        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        cout<<longest_subarray(arr, sum)<<endl;
    }
}
