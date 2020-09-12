#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


int maximum_distinck_elements(vector<int> arr, int k){
    unordered_map<int,int> hash;
    priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>> > pq;

    for(int x:arr){
        if(hash.find(x) == hash.end())
            hash[x] = 1;
        else
            hash[x] += 1;
    }

    for(pair<int,int> p:hash){
        pq.push(make_pair(p.second,p.first));
    }

    for(int i = 0 ; i < k ; i++){
        pair<int,int> top = pq.top();
        pq.pop();
        top.first -= 1;
        if(top.first != 0)
            pq.push(top);
    }

    return pq.size();
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n,k;cin>>n>>k;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        cout<<maximum_distinck_elements(arr, k)<<endl;
    }
}
