#include <iostream>
#include <vector>

using namespace std;

// Problem Link : https://practice.geeksforgeeks.org/problems/length-of-longest-subarray/0

int longest_subarray(const vector<int> &arr){

    int max_of_all = 0;
    int current_max = 0;

    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] >= 0){
            current_max++;
            if(arr[arr.size() - 1] >= 0)
                max_of_all = max(max_of_all,current_max);
        }
        else{
            max_of_all = max(max_of_all, current_max);
            current_max = 0;
        }
    }

    return max_of_all;
}


int main(){
    int testcase;
    cin>>testcase;

    for(int tc = 0 ; tc < testcase ; tc++ ){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < arr.size() ; i++){
            int value;cin>>value;
            arr[i] = value;
        }
        cout<<longest_subarray(arr)<<endl;
    }
}
