#include <iostream>

using namespace std;

void printBinaryWithEqualHalfSumUtil(int n, string left, string right, int leftSum, int rightSum){
    if(n > 1){
        printBinaryWithEqualHalfSumUtil(n-2, left + "0",right + "0", leftSum, rightSum);
        printBinaryWithEqualHalfSumUtil(n-2, left + "0", right + "1", leftSum, rightSum + 1);
        printBinaryWithEqualHalfSumUtil(n-2, left + "1", right + "0", leftSum + 1, rightSum);
        printBinaryWithEqualHalfSumUtil(n-2, left + "1",right + "1", leftSum + 1, rightSum+1);
    }
    else if(leftSum == rightSum){
        if(n == 1){
            cout<<left<<"0"<<right<<" ";
            cout<<left<<"1"<<right<<" ";
        }else
            cout<<left<<right<<" ";
    }
}

void printBinaryWithEqualHalfSum(int n){
    printBinaryWithEqualHalfSumUtil(n, "", "", 0, 0);
}

int main()
{
    int n = 5;
    printBinaryWithEqualHalfSum(n);
}
