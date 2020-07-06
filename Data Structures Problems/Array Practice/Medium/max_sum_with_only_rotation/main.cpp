#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/max-sum-in-the-configuration/1

// We have to Max Sum(i * arr[i]) with only rotaions on given array allowed

// Time Complexity O(n)
// Space Complexity O(1)

int max_rotation_sum(vector<int> arr){
    int arr_sum = accumulate(arr.begin(),arr.end(),0);

    int indexSum = 0;
    for(int i = 0 ; i < arr.size(); i++)
        indexSum += i * arr[i];

    int max_sum = indexSum;
    for(int i = 0,right=arr.size()-1 ; i < arr.size() - 1 ; i++,right--){
        indexSum = (indexSum + arr_sum) - (arr.size()) * arr[right];
        max_sum = max(max_sum,indexSum);
    }

    return max_sum;
}

int main()
{
    vector<int> arr = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout<<max_rotation_sum(arr)<<endl;
}
