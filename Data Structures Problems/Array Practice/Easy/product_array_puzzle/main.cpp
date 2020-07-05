#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/product-array-puzzle/0

void product_array(vector<int> &arr){
    int arr_product = accumulate(arr.begin(),arr.end(),1, multiplies<int>());

    for(int i = 0; i < arr.size() ; i++){
        cout<<arr_product/arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int N;cin>>N;
        vector<int> arr(N);
        for(int j = 0 ; j < N; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        product_array(arr);
    }
}
