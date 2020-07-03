#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Problem Link :: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

void printVec(vector<int> &arr, int left, int right){
    for(int i = left; i <= right;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Partition Slow dont use
//    int pivot = arr[(rand() % (right - left + 1)) + left];
//    int i,j;

//    int count = 0;
//    for(i = left,j=right ; i < j ;){
//        count++;
//        if(arr[i] >= pivot){
//            if(arr[j] <= pivot){
//                iter_swap(arr.begin()+i,arr.begin()+j);
//            }else j--;
//        }else i++;
//    }

int partition(vector<int> &arr, int left, int right){
    int pivot_index= (rand() % (right - left + 1)) + left;
    iter_swap(arr.begin()+left,arr.begin()+pivot_index);

    int i,j;

    for(i = left+1,j=left+1; j <= right ; j++){
        if(arr[j] < arr[left]){
            iter_swap(arr.begin()+i,arr.begin()+j);i++;
        }
    }

    iter_swap(arr.begin()+left,arr.begin()+i-1);
    return i-1;
}

// Time Complexity O(nlogn) in average
// Space Complexity O(1)
int kth_smallest(vector<int> &arr, int left, int right, int k){
    if(left == right)
        return arr[left];

    int i = partition(arr, left, right);

    if(k == i+1)
        return arr[i];
    else if(k > i + 1)
        return kth_smallest(arr, i+1, right, k);
    else
        return kth_smallest(arr, left, i-1, k);
}

int main()
{
    vector<int> arr={ -3,-1,-44,12, 3, 5, -43,-554,7, 4, 19, 26,3423,-2345,1234123,55,0,-13241 };
//    vector<int> arr={7,10,4,20,15};
    srand(time(0));
    for(int k = 1 ; k <= arr.size(); k++){
        cout<<kth_smallest(arr, 0, arr.size()-1, k)<<endl;
    }

    partition(arr,2,10);
}
