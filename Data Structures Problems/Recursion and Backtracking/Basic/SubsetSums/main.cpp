#include<bits/stdc++.h>
using namespace std;



class Solution
{
public:

    void subsetSumUtil(vector<int> &arr, int index, int sum, vector<int> &result){
        if(index >= arr.size()){
            result.emplace_back(sum);
            return;
        }
        subsetSumUtil(arr, index + 1, sum, result);

        sum += arr[index];
        subsetSumUtil(arr, index + 1, sum , result);
    }
    vector<int> subsetSums(vector<int> &arr, int N){
        vector<int> result;
        subsetSumUtil(arr, 0, 0, result);
        sort(result.begin(),result.end());
        return result;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
