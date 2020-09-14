#include <iostream>
#include <vector>

using namespace std;


void heapifyDown(vector<int> &arr, int index){
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
        heapifyDown(arr, largest);
    }
}

vector<int> merge_maxheaps(vector<int> heap1, vector<int> heap2){
    vector<int> merged_heap(heap1.size() + heap2.size());

    for(int i = 0 ; i < heap1.size() ; i++)
        merged_heap[i] = heap1[i];

    for(int i = heap1.size() ; i < merged_heap.size() ; i++)
        merged_heap[i] = heap2[i - heap1.size()];

    for(int i = (merged_heap.size()/2) - 1 ; i >= 0 ; i--){
        heapifyDown(merged_heap,i);
    }

    return merged_heap;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n1,n2;cin>>n1>>n2;
        vector<int> arr1(n1);
        vector<int> arr2(n2);

        for(int j = 0 ; j < n1 ; j++)
            cin>>arr1[j];
        for(int j = 0 ; j < n2 ; j++)
            cin>>arr2[j];

        vector<int> mergedMaxHeap = merge_maxheaps(arr1, arr2);

        for(int v:mergedMaxHeap)
            cout<<v<<" ";
        cout<<endl;
    }
}
