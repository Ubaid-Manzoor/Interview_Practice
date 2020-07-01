#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

// Algorithum to find if a pair exists with sum == sum

//Method I
// Algorithum used is called 2-pointer Algo
// Time Complexity O(nlogn)
// Space Complexity depend on the sorting algorithum sort() uses
bool pairExists_I(vector<int> arr, int sum){
    sort(arr.begin(), arr.end());
    for(int left=0,right=arr.size()-1; left < right;){
        if(arr[left] + arr[right] == sum)
            return true;
        if(sum > arr[left] + arr[right])
            left++;
        else
            right--;

    }
    return false;
}


// Method II
// using hash map
// Time Complexity is O(n)
// Space Complexity is O(n)
bool pairExists_II(vector<int> arr, int sum){
    unordered_set<int> number_set;

    for(int i = 0 ; i < arr.size(); i++){
        int second = sum - arr[i];
        if(number_set.find(second) != number_set.end()){
            cout<<arr[i]<<" + "<<second<<" = "<<sum<<endl;
            return true;
        }
        number_set.emplace(arr[i]);
    }
    return false;
}


int main(){
    vector<int> arr={1,4,45,6,10,-8};
    int sum = 16;
    if(pairExists_II(arr, sum))
        cout<<"It Exists"<<endl;
    else
        cout<<"It does not Exists"<<endl;


}
