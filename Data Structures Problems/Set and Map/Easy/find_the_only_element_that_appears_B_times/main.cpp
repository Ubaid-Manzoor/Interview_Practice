#include <iostream>
#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

int appearsBTimes(vector<int> arr, int a, int b){
    unordered_set<int> hashset;

    int correctSum=0, currentSum=0;

    for(int x:arr){
        currentSum += x;
        hashset.emplace(x);
    }

    correctSum = accumulate(hashset.begin(), hashset.end(), 0);
    correctSum *= a;

    return (correctSum - currentSum) / (a-b);
}

int main(){
    vector<int> arr = { 1, 1, 2, 2, 2, 3, 3, 3 };
    int a = 3, b = 2;
    cout << appearsBTimes(arr, a, b);
    return 0;
}
