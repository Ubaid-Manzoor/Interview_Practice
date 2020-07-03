#include <iostream>
#include <vector>

using namespace std;

void printVec(vector<int> &arr){
    for(int v:arr){
        cout<<v<<" ";
    }
    cout<<endl;
}

void moveZerosToEnd(vector<int> &arr){
    int nonZero_pointer=0;
    for(int i = 0 ; i < arr.size() and nonZero_pointer < arr.size();){
        if(arr[i] == 0){
            nonZero_pointer = max(i, nonZero_pointer);
            if(arr[nonZero_pointer] != 0){
                iter_swap(arr.begin()+i,arr.begin()+nonZero_pointer);
                i++;
            }
            nonZero_pointer++;
        }else i++;
    }
}

void moveZerosToEnd_I(vector<int> &arr){
    int count=0;
    for(int i=0; i < arr.size();i++){
        if(arr[i] != 0){
            arr[count] = arr[i];
            count++;
        }
    }

    for(int i = count ; i < arr.size() ; i++)
        arr[i] = 0;
}

// Problem Link :- https://www.geeksforgeeks.org/move-zeroes-end-array-set-2-using-single-traversal/
void moveZerosToEnd_II(vector<int> &arr){
    int count=0;
    for(int i=0; i < arr.size();i++){
        if(arr[i] != 0){
//            arr[count] = arr[i];
            iter_swap(arr.begin() + count, arr.begin() + i);
            count++;
        }
    }
}


int main()
{
//    vector<int> arr={1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    vector<int> arr={1, 2, 0, 4, 3, 0, 5, 0};
//    vector<int> arr={1, 2, 0, 0, 0, 3, 6};
//    vector<int> arr={0,0,0,0};
//    vector<int> arr={1,2,3,4,0,0,0,0};
//    vector<int> arr={0,0,0,0,1,2,3,4};
//    vector<int> arr={0,0,0,0,1,2,3,4,0,0,0};
    moveZerosToEnd_II(arr);
    printVec(arr);
}
