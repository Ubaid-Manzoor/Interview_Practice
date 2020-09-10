// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


/* Function to print an array */

// Driver program to test above functions
int main()
{
    int arr[1000000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    heapSort(arr, n);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[].
// n is size of heap. This function  is used in above heapSor()

int leftChild(int pos){
    return 2 * pos + 1;
}

int rightChild(int pos){
    return 2 * pos + 2;
}

bool isLeaf(int pos, int size){
    if(leftChild(pos) >= size)
        return true;
    return false;
}


void heapify(int arr[], int n, int i)  {
      // Your Code Here
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n and arr[l] > arr[largest])
        largest = l;
    if(r < n and arr[r] > arr[largest])
        largest = r;

    if(largest != i){
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Rearranges input array so that it becomes a max heap
void buildHeap(int arr[], int n)  {
    // Your Code Here

    for(int i = (n-1)/2
        ; i >= 0 ; i--)
        heapify(arr, n, i);
}






