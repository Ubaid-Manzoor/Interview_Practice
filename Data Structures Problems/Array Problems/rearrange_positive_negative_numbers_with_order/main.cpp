#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVec(vector<int> &arr){
    for(int v:arr)
        cout<<v<<" ";
    cout<<endl;
}

void rotate(vector<int> &arr, int low, int mid, int high){
    reverse(arr.begin()+low,arr.begin()+mid+1);
    reverse(arr.begin()+mid+1,arr.begin()+high);
    reverse(arr.begin()+low, arr.begin()+high);
}

void modified_merge(vector<int> &arr, int left, int mid, int right){
    while(arr[right] > 0 and mid < right){
        right--;
    }

    while(arr[left] < 0 and left <= mid){
        left++;
    }

    rotate(arr, left, mid, right+1);
}


// Time Complexity O(nlogn)
// Space Complexity O(1)
void rearrange(vector<int> &arr, int left, int right){
    if(left == right)
        return;
    int mid = (left + right) / 2;

    rearrange(arr, left, mid);
    rearrange(arr, mid+1, right);

    modified_merge(arr, left, mid, right);
}

int main()
{
//        vector<int> arr = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
//        vector<int> arr = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
//        vector<int> arr = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
//        vector<int> arr = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 };
    vector<int> arr = { -12, 11, -13, -5, 6, -7, 5, -3, -6 } ;
    rearrange(arr, 0, arr.size()-1);
    printVec(arr);
}
