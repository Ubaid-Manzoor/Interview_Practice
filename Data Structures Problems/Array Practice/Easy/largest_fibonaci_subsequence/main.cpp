#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>


using namespace std;

void printSet(unordered_set<int> fib_set){
    for(int fib_num:fib_set)
        cout<<fib_num<<" ";
    cout<<endl;
}

void printVec(vector<int> fib_vec){
    for(int fib_num:fib_vec)
        cout<<fib_num<<" ";
    cout<<endl;
}

unordered_set<int> fibonacci_set(int max_num){

    int one=0,second=1;
    unordered_set<int> fib_set;
    fib_set.emplace(0);
    while(max_num >= one + second){
        int third = one + second;
        fib_set.emplace(third);
        one = second;
        second = third;
    }

    return fib_set;
}

void largest_fibonacci_subsequence(vector<int> &arr){

    int max_num = *max_element(arr.begin(), arr.end());
    unordered_set<int> fib_set = fibonacci_set(max_num);

    vector<int> fib_sequence;
    for(int i = 0 ; i < arr.size() ; i++){
        if(fib_set.find(arr[i]) != fib_set.end()){
            fib_sequence.emplace_back(arr[i]);
        }
    }

    printVec(fib_sequence);
}


int main(){
    vector<int> arr={1,2,3,4,5,6,7,89};
    largest_fibonacci_subsequence(arr);
}
