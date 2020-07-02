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

int main()
{
//    vector<int> arr={1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
//    vector<int> arr={1, 2, 0, 4, 3, 0, 5, 0};
//    vector<int> arr={1, 2, 0, 0, 0, 3, 6};
//    vector<int> arr={0,0,0,0};
//    vector<int> arr={1,2,3,4,0,0,0,0};
//    vector<int> arr={0,0,0,0,1,2,3,4};
    vector<int> arr={0,0,0,0,1,2,3,4,0,0,0};
    moveZerosToEnd(arr);
    printVec(arr);
}
