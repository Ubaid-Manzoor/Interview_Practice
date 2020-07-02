#include <iostream>
#include <vector>

using namespace std;

// Link of the Problem :- https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

void printVec(vector<int> arr){
    for(int v:arr)
        cout<<v<<" ";
    cout<<endl;
}

void rotate(vector<int> &arr, int start, int end){
    int temp = arr[end];
    for(int i = end; i > start ; i--){
        arr[i] = arr[i - 1];
    }
    arr[start] = temp;
}

bool isodd(int num){
    return (num % 2) != 0;
}

bool iseven(int num){
    return (num % 2) == 0;
}

bool isnegative(int num){
    return num < 0;
}

bool ispositive(int num){
    return num >= 0;
}

// Time Complexity O(n) if we dont maintain_order and O(n^2) otherwise
// Space Complexity O(1)
void rearrange_I(vector<int> &arr, bool maintain_order=false){
    int positive_pointer=0,negative_pointer=0;
    for(int i = 0 ; i < arr.size(); i++){
        if(isodd(i) and isnegative(arr[i])){
            positive_pointer = max(i+1,positive_pointer);
            for(;positive_pointer < arr.size();positive_pointer++){
                if(ispositive(arr[positive_pointer])){
                    if (maintain_order)
                        rotate(arr, i, positive_pointer);
                    else
                        iter_swap(arr.begin() + i, arr.begin() + positive_pointer);
                    positive_pointer++;break;
                }
            }
        }
        else if(iseven(i) and ispositive(arr[i])){
            negative_pointer = max(i+1,negative_pointer);
            for(;negative_pointer < arr.size();negative_pointer++){
                if(isnegative(arr[negative_pointer])){
                    if(maintain_order)
                        rotate(arr, i, negative_pointer);
                    else
                        iter_swap(arr.begin() + i, arr.begin() + negative_pointer);
                    negative_pointer++;break;
                }
            }
        }
    }
}

void rearrange_II(vector<int> &arr){

    // Partition the Array into negative and positive

    // OTHER METHOD TO PARTITION
    //    int positive_pointer=0;
    //    for(int i = 0 ; i < arr.size() and positive_pointer < arr.size();){
    //        if(arr[i] < 0){
    //            if(arr[positive_pointer] > 0)
    //                iter_swap(arr.begin() + i, arr.begin() + positive_pointer);
    //            positive_pointer++;
    //        }else i++;
    //    }

    int left,right;
    for(left=0,right=arr.size()-1; left < right;){
        if(arr[left] < 0){
            if(arr[right] >= 0){
                iter_swap(arr.begin()+left, arr.begin()+right);left++;
            }
            else right--;
        }else left++;

    }

    // left points to first -ve value in arr after partition
    for(int i = 1 ; i < arr.size() and left < arr.size() ; i += 2){
        if(arr[i] >= 0)
            iter_swap(arr.begin()+i, arr.begin()+left);left++;
    }

}


int main(){
//    vector<int> arr = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
//    vector<int> arr = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
//    vector<int> arr = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
//    vector<int> arr = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
    vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrange_II(arr);
    printVec(arr);
}
