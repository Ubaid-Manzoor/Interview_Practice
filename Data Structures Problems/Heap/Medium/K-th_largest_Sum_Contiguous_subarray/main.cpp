#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int kthLargestSum(vector<int> arr, int k){
    int n = arr.size();
    vector<int> maxheap;
    maxheap.reserve(n*n);

    for(int i = 0 ; i < n ; i++){
        int current_sum = arr[i];
        maxheap.emplace_back(current_sum);
        for(int j = i+1 ; j < n ; j++){
            current_sum += arr[j];
            maxheap.emplace_back(current_sum);
        }
    }

    make_heap(maxheap.begin(), maxheap.end());

    for(int i = 1 ;i < k ; i++){
        pop_heap(maxheap.begin(), maxheap.end());
        maxheap.pop_back();
    }

    return maxheap.front();
}

int main()
{
    vector<int> arr = { 10, -10, 20, -40 };
    int k = 6;
//    vector<int> arr = { 20, -5, -1 };
//    int k = 3;

    // calls the function to find out the
    // k-th largest sum
    cout << kthLargestSum(arr, k)<<endl;
    return 0;
}
