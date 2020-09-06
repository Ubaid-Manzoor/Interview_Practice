#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    int parent(int childIndex){
        return (childIndex-1) / 2;
    }

    int leftChild(int parentIndex){
        return 2 * parentIndex + 1;
    }

    int rightChild(int parentIndex){
        return 2 * parentIndex + 2;
    }

    bool isLeaf(int pos){
        int left = 2 * pos + 1;
        int right = left + 1;
        if(left >= size  and right > size)
            return true;
        return false;
    }

    void HeapifyDown(int pos){
        if(isLeaf(pos))
            return;

        if(arr[pos] < arr[leftChild(pos)] or arr[pos] < arr[rightChild(pos)]){
            if(arr[leftChild(pos)] > arr[rightChild(pos)]){
                swap(arr[pos], arr[leftChild(pos)]);
                HeapifyDown(leftChild(pos));
            }
            else{
                swap(arr[pos], arr[rightChild(pos)]);
                HeapifyDown(rightChild(pos));
            }
        }
    }


public:
    vector<int> arr;
    int size;
    int maxSize;
    MaxHeap(int maxsize){
        arr.resize(maxsize);
        size = 0;
        maxSize = maxsize;
    }

    void insert(int data){
        if(size >= maxSize)
            return;

        arr[size] = data;

        int currentIndex = this->size;
        while(currentIndex != 0 and arr[parent(currentIndex)] < arr[currentIndex]){
            swap(arr[parent(currentIndex)], arr[currentIndex]);
            currentIndex = parent(currentIndex);
        }

        size++;
    }

    int extractMax(){
        int max = arr[0];
        arr[0] = arr[--size];

        arr.pop_back();
        HeapifyDown(0);


        return max;
    }
};

int main(){
    MaxHeap H(8);

    H.insert(3);
    H.insert(1);
    H.insert(2);
    H.insert(55);
    H.insert(33);
    H.insert(14);
    H.insert(25);
    H.insert(565);


    while(H.size > 0)
        cout<<H.extractMax()<<endl;
}
