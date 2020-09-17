#include <iostream>
#include <algorithm>

using namespace std;

int nobleInteger(int arr[], int n){
    sort(arr, arr + n);

    for(int i = 0 ; i < n ; i++){
        if(i < n-1 and arr[i] == arr[i + 1])
            continue;

        if(arr[i] == n - (i + 1))
            return arr[i];
    }

    return -1;
}



int main()
{
//    int arr[] = {10, 3, 20, 40, 2};
    int arr[] = {-1, -9, -2, -78, 0};
    int res = nobleInteger(arr, 5);
    if (res != -1)
        cout << "The noble integer is " << res;
    else
        cout << "No Noble Integer Found";
    cout<<endl;
    return 0;
}
