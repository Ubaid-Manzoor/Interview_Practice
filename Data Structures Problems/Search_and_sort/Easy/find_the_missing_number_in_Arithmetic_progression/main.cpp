#include <iostream>

using namespace std;

int findMissingInAP(int ap[], int n){
    int l = 0;
    int r = n-1;

    int mid,s=ap[0], diff = ap[1] - ap[0];
    while(r >= l){
        mid = l + (r - l)/2;

        if(ap[mid] == s + mid * diff)
            l = mid + 1;
        else{
            if(ap[mid - 1] != ap[mid] - diff)
                return ap[mid] - diff;
            r = mid - 1;
        }
    }
}

int main()
{
//    int arr[] = {2, 4, 8, 10, 12, 14};
    int arr[] = {1, 6, 11, 16, 21, 31};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The missing element is "
         << findMissingInAP(arr, n);
    return 0;
}
