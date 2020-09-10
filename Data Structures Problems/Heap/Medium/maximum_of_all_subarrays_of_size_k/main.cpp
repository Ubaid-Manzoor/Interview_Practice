#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int findIndex(vector<int> arr, int value){
    for(int i = 0 ;i < arr.size() ; i++)
        if(arr[i] == value)
            return i;
}

int parent(int childIndex){
    return (childIndex - 1)/2;
}

int leftChild(int parentIndex){
    return 2 * parentIndex + 1;
}

int rightChild(int parentIndex){
    return 2 * parentIndex + 2;
}

void HeapifyUp(vector<int> &heap, int index){
    if(index == 0)
        return;

    if(heap[parent(index)] < heap[index]){

        swap(heap[parent(index)], heap[index]);
        HeapifyUp(heap, parent(index));
    }
}

void HeapifyDown(vector<int> &heap , int index){
    int left = leftChild(index);
    int right = rightChild(index);
    int largest = index;

    if(left < heap.size() and heap[left] > heap[largest])
        largest = left;

    if(right < heap.size() and heap[right] > heap[largest])
        largest = right;

    if(largest != index){
        swap(heap[index], heap[largest]);
        HeapifyDown(heap, largest);
    }
}

void printArr(vector<int> arr){
    cout<<"Arr : ";
    for(int a:arr)
        cout<<a<<" ";
    cout<<endl;
}

vector<int> maxInK(vector<int> arr, int k){
    vector<int> maxheap(arr.begin(), arr.begin() + k);
    make_heap(maxheap.begin(), maxheap.end());
    vector<int> maxValue;maxValue.emplace_back(maxheap.front());

    int last, next, l_i=0, n_i=k;
    last = arr[l_i];
    next = arr[n_i];

    for(int i = k; i < arr.size() ; i++){
        int Index = findIndex(maxheap, last);
        maxheap[Index] = next;
        HeapifyDown(maxheap, Index);
        HeapifyUp(maxheap, Index);

        maxValue.emplace_back(maxheap.front());
        last = arr[++l_i];
        next = arr[++n_i];
    }

    return maxValue;
}

int main(){
    int tc;
    cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n, k;cin>> n >> k;
        vector<int> arr(n);

        for(int j = 0 ;j < n ; j++){
            cin>>arr[j];
        }

        vector<int> maxArr = maxInK(arr, k);
        for(int maxV:maxArr)
            cout<<maxV<<" ";
        cout<<endl;
    }
}
