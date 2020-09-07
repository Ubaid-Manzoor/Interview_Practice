#include <iostream>
#include <vector>

using namespace std;

class MinHeap {
private:
    bool isLeaf(int pos){
        if(leftChild(pos) >= size)
            return true;
        return false;
    }

    int leftChild(int parentIndex){
        return 2 * parentIndex + 1;
    }

    int rightChild(int parentIndex){
        return 2 * parentIndex + 2;
    }

    int parent(int childIndex){
        return (childIndex-1)/2;
    }

    void HeapifyDown(int pos){
        if(isLeaf(pos))
            return;

        if(arr[leftChild(pos)] < arr[pos] or arr[rightChild(pos)] < arr[pos]){
            if(arr[leftChild(pos)] < arr[rightChild(pos)]){
                swap(arr[pos],arr[leftChild(pos)]);
                HeapifyDown(leftChild(pos));
            }else{
                swap(arr[pos], arr[rightChild(pos)]);
                HeapifyDown(rightChild(pos));
            }
        }
    }

public:
    vector<int> arr;
    int size,maxSize;

    MinHeap(int maxsize){
        arr.resize(maxsize);
        size=0;
        maxSize = maxsize;
    }

    void insert(int data){
        if(size == maxSize)
            return;

        arr[size] = data;

        int current = size;
        while(current != 0 and arr[current] < arr[parent(current)]){
            swap(arr[parent(current)],arr[current]);
            current = parent(current);
        }

        size++;
    }

    int extractMin(){
        int min = arr[0];

        arr[0] = arr[size-1];
        arr.pop_back();

        size--;
        HeapifyDown(0);

        return min;
    }

};

int main(){
    MinHeap H(6);

    H.insert(3);
    H.insert(2);
    H.insert(4);
    H.insert(33);
    H.insert(1);
    H.insert(55);

    while(H.size != 0)
        cout<<H.extractMin()<<" ";
    cout<<endl;
}
