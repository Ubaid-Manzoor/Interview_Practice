#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVec(vector<int> v){
    for(auto value:v){
        cout<<value<<" ";
    }
    cout<<endl;
}


// Time Complexity O(n * d)
// Space Complexity O(1)
void rotate(vector<int> &to_rotate,int d){
    for(int i = 0 ; i < d ; i++){
        int remember_last = to_rotate.back();
        for(int j = to_rotate.size() - 1 ; j > 0 ; j--){
            to_rotate[j] = to_rotate[j-1];
        }
        to_rotate[0] = remember_last;
    }
}


// Time Complexity O(n + d)
// Space Complexity O(d)
void rotate_(vector<int> &to_rotate, int d){
    // Save the last D element in a temp vector
    vector<int> temp(to_rotate.end()-d,to_rotate.end());
    for(int j = to_rotate.size() - 1 ; j - d >= 0 ; j--)
         to_rotate[j] = to_rotate[j-d];
    for(int i = 0 ; i < d ; i++)
        to_rotate[i] = temp[i];
}


// Time Complexity O(n)
// Space Complexity O(1)
void right_rotate(vector<int> &to_rotate, int d){
    reverse(to_rotate.begin(), to_rotate.end());
    reverse(to_rotate.begin(), to_rotate.begin() + d);
    reverse(to_rotate.begin() + d, to_rotate.end());
}


// Time Complexity O(n)
// Space Complexity O(1)
void left_rotate(vector<int> &to_rotate, int d){
    reverse(to_rotate.begin(), to_rotate.end());
    reverse(to_rotate.begin(), to_rotate.end() - d);
    reverse(to_rotate.end() - d, to_rotate.end());
}


int main()
{
    vector<int> to_rotate={1,2,3,4,5,6,7};

    left_rotate(to_rotate, 3);
    printVec(to_rotate);
}
