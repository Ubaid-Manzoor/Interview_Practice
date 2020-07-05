#include <iostream>
#include <numeric>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/equilibrium-index-of-an-array/1

int equilibrium_index(int arr[], int n){
    int arr_sum = accumulate(arr, arr + n,0);

    int left_sum=arr[0],right_sum=arr_sum - arr[0] - arr[1];

    for(int i = 1 ; i < n - 1 ; i++){
        if(left_sum == right_sum){
            return i;
        }else{
            if(i == n - 2 and left_sum != right_sum)
                return -1;
            left_sum += arr[i];
            right_sum -= arr[i+1];
        }
    }

}

int main()
{
    int arr[] = {1,1,1,1};
    cout<<equilibrium_index(arr, 4)<<endl;
}
