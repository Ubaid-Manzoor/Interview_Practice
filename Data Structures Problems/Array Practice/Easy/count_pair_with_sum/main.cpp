#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;


int count_pairs(vector<int> &arr, int sum){
    unordered_map<int,int> counter;
    for(int i = 0 ; i < arr.size() ; i++){
        if(counter.find(arr[i]) == counter.end())
            counter[arr[i]] = 1;
        else
            counter[arr[i]] += 1;
    }

    unordered_set<int> seen;
    int pair_count = 0;
    for(pair<int,int> p:counter){
        int number = p.first;
        int count = p.second;
        if(seen.find(number) == seen.end()){
            int other_num = sum - number;
            if(counter.find(other_num) != counter.end()){
                if(other_num == number)
                    pair_count += ((count - 1) * count) / 2; // Formula of sum of n natural numbers
                else
                    pair_count += (count) * counter[other_num];
                seen.emplace(other_num);
            }
        }
    }

    return pair_count;
}


int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int N;int sum;
        cin>>N>>sum;
        vector<int> arr(N);
        for(int j = 0 ; j < N ; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        cout<<count_pairs(arr, sum)<<endl;
    }
}





