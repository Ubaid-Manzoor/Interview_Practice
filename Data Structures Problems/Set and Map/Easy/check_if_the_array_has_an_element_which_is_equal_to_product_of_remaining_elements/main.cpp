#include <iostream>
#include <unordered_set>
#include <numeric>
#include <math.h>

using namespace std;

bool ifExist(int arr[], int n){
    int arrayProduct = accumulate(arr, arr + n, 1, multiplies<int>());

    for(int i = 0 ; i < n ; i++){
        if(arrayProduct % arr[i] == 0 and arrayProduct / arr[i] == arr[i])
            return true;
    }

    return false;
}


// Using Unordered Set
bool ifExist_(int arr[], int n){
    int arrayProduct = accumulate(arr, arr + n, 1, multiplies<int>());
    unordered_set<int> hashset(arr, arr+n);

    int squareRoot = sqrt(arrayProduct);
    if(squareRoot * squareRoot == arrayProduct){
        if(hashset.find(squareRoot) != hashset.end())
            return true;
    }
    return false;

}


int main()
{
//    int arr[] = { 1, 2, 12, 3, 2 };
    int arr[] = { 1, 2, 12, 3, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    if (ifExist_(arr, n))
        cout << "YES";

    else
        cout << "NO";

    cout<<endl;

    return 0;
}
