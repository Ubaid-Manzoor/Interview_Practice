#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printMedianInStream(vector<int> stream){
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;

    for(int s:stream){
        if(maxheap.empty())
            maxheap.push(s);
        else{
            if(s < maxheap.top()){
                maxheap.push(s);
                if(maxheap.size() - minheap.size() > 1){
                    minheap.push(maxheap.top());
                    maxheap.pop();
                }
            }else{
                minheap.push(s);

                if(minheap.size() - maxheap.size() > 1){
                    maxheap.push(minheap.top());
                    minheap.pop();
                }
            }
        }

        if(minheap.size() == maxheap.size())
            cout<< ( minheap.top() + maxheap.top() ) / 2<<endl;
        else if(minheap.size() > maxheap.size()){
            cout<<minheap.top()<<endl;
        }else{
            cout<<maxheap.top()<<endl;
        }
    }
}

int main()
{
    int n;cin>>n;

    vector<int> arr(n);
    for(int j = 0 ; j < n ; j++){
        cin>>arr[j];
    }

    printMedianInStream(arr);
}
