#include <iostream>
#include <queue>

using namespace std;

void LargestTripletMultiplication(int stream[], int n){
    vector<int> maxheap(stream, stream+3);
    make_heap(maxheap.begin(), maxheap.end());

    for(int i = 0 ;i < n ; i++){
        if(i < 2)
            cout<<"-1"<<endl;
        else{
            int first = maxheap[0];
            int second = maxheap[1];
            int third = maxheap[2];

            if(i > 2){
                if(stream[i] > first or stream[i] > second or stream[i] > third){
                    if(third > second)
                        swap(maxheap[2], maxheap[1]);
                    maxheap.pop_back();
                    maxheap.emplace_back(stream[i]);
                    push_heap(maxheap.begin(), maxheap.end());
                }
            }
            int triplet_product = maxheap[0] * maxheap[1] * maxheap[2];
            cout<<triplet_product<<endl;
        }
    }
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    LargestTripletMultiplication(arr, n);
    return 0;
}
