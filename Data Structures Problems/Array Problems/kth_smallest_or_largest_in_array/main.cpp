#include <iostream>
#include <vector>
#include <random>

using namespace std;

// Problem Link :: https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/

void printVec(vector<int> &arr){
    for(int v:arr){
        cout<<v<<" ";
    }
    cout<<endl;
}


// Time Complexity O(nlogn) in average
// Space Complexity O(1)
int kth_smallest(vector<int> &arr, int left, int right, int k){
    if(left == right)
        return arr[left];

    // Partition
    int pivot = arr[rand() % arr.size()];
    int i,j;
    for(i = 0,j=arr.size()-1 ; i < j ;){
        if(arr[i] >= pivot){
            if(arr[j] <= pivot){
                iter_swap(arr.begin()+i,arr.begin()+j);
            }else j--;
        }else i++;
    }

    if(k == i+1)
        return arr[i];
    else if(k > i + 1)
        kth_smallest(arr, i+2, right, k);
    else
        kth_smallest(arr, i, right, k);
}

int main()
{
    vector<int> arr={ -3,-1,-44,12, 3, 5, -43,-554,7, 4, 19, 26,3423,-2345,1234123,55,0,-13241 };
    srand(time(0));
    for(int k = 1 ; k < arr.size()+1; k++){
        cout<<k<<" :: ";
        cout<<kth_smallest(arr, 0, arr.size(), k)<<endl;
    }
}
