#include <iostream>

using namespace std;

int getMin(int arr[], int n){
    return (n == 1) ? arr[0] : min(arr[0],getMin(arr + 1, n-1));
}

int getMax(int arr[], int n){
    return (n == 1) ? arr[0] : max(arr[0], getMax(arr + 1, n-1));
}

int main()
{
    int arr[] = { 12, 1234, 45, 67, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum element of array: " <<
                            getMin(arr, n) << "\n";
    cout << "Maximum element of array: " <<
                                   getMax(arr, n);
    return 0;
}
