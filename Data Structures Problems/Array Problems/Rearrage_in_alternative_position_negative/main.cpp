#include <iostream>
#include <vector>

using namespace std;

// Link of the Problem :- https://www.geeksforgeeks.org/rearrange-array-alternating-positive-negative-items-o1-extra-space/

void printVec(vector<int> arr){
    for(int v:arr)
        cout<<v<<" ";
    cout<<endl;
}

void rotate(vector<int> &arr){

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

// Time Complexity O(n^2)
// Space Complexity O(1)
void rearrange(vector<int> &arr){
    int positive_pointer=0,negative_pointer=0;

    for(int i = 0 ; i < arr.size(); i++){
        if(isodd(i) and isnegative(arr[i])){
            positive_pointer = max(i+1,positive_pointer);
            for(;positive_pointer < arr.size();positive_pointer++){
                if(ispositive(arr[positive_pointer])){
                    iter_swap(arr.begin() + i, arr.begin() + positive_pointer);
                    positive_pointer++;break;
                }
            }
        }
        else if(iseven(i) and ispositive(arr[i])){
            negative_pointer = max(i+1,negative_pointer);
            for(;negative_pointer < arr.size();negative_pointer++){
                if(isnegative(arr[negative_pointer])){
                    iter_swap(arr.begin() + i, arr.begin() + negative_pointer);
                    negative_pointer++;break;
                }
            }
        }
    }
}


int main(){
//    vector<int> arr = {-5, 3, 4, 5, -6, -2, 8, 9, -1, -4};
//    vector<int> arr = {-5, -3, -4, -5, -6, 2 , 8, 9, 1 , 4};
//    vector<int> arr = {5, 3, 4, 2, 1, -2 , -8, -9, -1 , -4};
//    vector<int> arr = {-5, 3, -4, -7, -1, -2 , -8, -9, 1 , -4};
    vector<int> arr = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    rearrange(arr);
    printVec(arr);
}
