#include<bits/stdc++.h>
using namespace std;

// Function to find minimum swaps to sort an array

void inOrder(vector<int> &inOrderArr, vector<int> &binaryTreeArr, int current){

}

int minSwaps(std::vector<int> &v){
    vector<int> inOrderArr;
    inOrder(inOrderArr,v,0);
}

// Driver code
int main()
{
    int a[] = { 5, 6, 7, 8, 9, 10, 11 };
    int n = sizeof(a) / sizeof(a[0]);
    std::vector<int> v;
    inorder(a, v, n, 0);
    cout << minSwaps(v) << endl;
}
