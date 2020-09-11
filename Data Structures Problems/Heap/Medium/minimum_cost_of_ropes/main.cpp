#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long int minimumCost(vector<long long int> ropes){
    priority_queue<long long int, vector<long long int>, greater<long long int>> minheap;

    for(int length: ropes){
        minheap.push(length);
    }

    long long int totalCost = 0;

    while(not minheap.empty()){
        long long int Length1 = minheap.top();minheap.pop();
        long long int Lenght2 = minheap.top();minheap.pop();

        totalCost = totalCost + Length1 + Lenght2;
        if(not minheap.empty())
            minheap.push(Length1 + Lenght2);
    }
    return totalCost;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        vector<long long int> ropes(n);
        for(int j = 0 ; j < n ; j++){
            cin>>ropes[j];
        }

        long long int cost = minimumCost(ropes);
        cout<<cost<<endl;
    }
}
