#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void ifZeroSumSubArrayExists(vector<int> arr){
    unordered_set<int> hashset;

    for(int i = 0 ; i < arr.size() ; i++){
        if(i != 0){
            arr[i] += arr[i-1];
            if(hashset.count(arr[i]) == 1 or arr[i] == 0){
                cout<<"Yes"<<endl;
                return;
            }
        }

        hashset.emplace(arr[i]);
    }

    cout<<"No"<<endl;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        ifZeroSumSubArrayExists(arr);
    }
}
