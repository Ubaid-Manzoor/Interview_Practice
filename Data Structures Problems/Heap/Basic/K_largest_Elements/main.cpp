#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> k_largest_elements(vector<int> arr, int k){
    vector<int> minheap;
    vector<int> k_largest;
    make_heap(minheap.begin(), minheap.end(), greater<int>());

    for(int i = 0 ; i < k ; i++){
        minheap.emplace_back(arr[i]);
        push_heap(minheap.begin(), minheap.end(), greater<int>());
    }


    for(int i = k ; i < arr.size() ; i++){
        if(arr[i] > minheap.front()){
            minheap.emplace_back(arr[i]);
            push_heap(minheap.begin(), minheap.end(), greater<int>());
            pop_heap(minheap.begin(), minheap.end(), greater<int>());
            minheap.pop_back();
        }
    }

    while(not minheap.empty()){
        k_largest.emplace_back(minheap.front());
        pop_heap(minheap.begin(), minheap.end(), greater<int>());
        minheap.pop_back();
    }

    return k_largest;
}

int main(){
    int tc;cin>>tc;

    for(int i = 0 ;i < tc ; i++){
        int n, k;cin>>n>>k;

        vector<int> arr(n);

        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        vector<int> k_largest = k_largest_elements(arr, k);

        for(int i = k_largest.size()-1 ; i >= 0 ; i--)
            cout<<k_largest[i]<<" ";
        cout<<endl;
    }
}
