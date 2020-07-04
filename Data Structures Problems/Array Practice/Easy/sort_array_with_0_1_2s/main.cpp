#include <iostream>

using namespace std;

void sort012(int a[], int n){

    int current_number=0;
    for(int left = 0,right=0 ; left < n ; ){
        if(a[right] == current_number){
            a[right] = a[left];
            a[left] = current_number;
            left++;
        }
        if(right == n-1){
            right = ((right + 1) % n) + left;
            current_number++;
        }
        else
            right++;
    }

}

int main()
{
    int a[] = {0,2,1,2,0,2};
    sort012(a, 6);
}
