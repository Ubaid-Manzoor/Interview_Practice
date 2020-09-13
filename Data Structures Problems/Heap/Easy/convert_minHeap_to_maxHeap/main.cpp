#include <iostream>
#include <vector>

using namespace std;

void printArr(vector<int> arr){
    for(int v:arr)
        cout<<v<<" ";
    cout<<endl;
}


void HeapifyDown(vector<int> &arr , int index){
    int n = arr.size();
    int l = 2 * index + 1;
    int r = 2 * index + 2;
    int largest = index;

    if(l < n and arr[l] > arr[largest])
        largest = l;
    if(r < n and arr[r] > arr[largest])
        largest = r;

    if(largest != index){
        swap(arr[largest], arr[index]);
        HeapifyDown(arr, largest);
    }

}

void convertToMaxHeap(vector<int> &arr){
    int n = arr.size();
    for(int i = (n - 1) / 2; i >= 0 ; i--)
        HeapifyDown(arr,i);
}

int main()
{
    // array representing Min Heap
    vector<int> arr = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};

    printf("Min Heap array : ");
    printArr(arr);

    convertToMaxHeap(arr);

    printf("\nMax Heap array : ");
    printArr(arr);

    return 0;
}
