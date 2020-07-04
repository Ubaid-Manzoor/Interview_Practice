#include <iostream>

using namespace std;


// Time Complexity O(n) ~ O(3n)
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


// Not Test yet but If work will be faster then above
void sort012_I(int a[], int n){
    for(int low=0,mid=0,high=n-1; mid < high;){
        if(a[mid] == 0){
            a[mid] = a[low];
            a[low] = 0;
            mid++;low++;
        }else if(a[mid] == 2){
            a[mid] = a[high];
            a[high] = 2;
            high--;
        }else
            mid++;
    }

    for(int i = 0 ; i < n ; i++)
            cout<<a[i]<<" ";
    cout<<endl;

}



int main()
{
    int a[] = {2,1,2,0};
    sort012_I(a, 4);
}
