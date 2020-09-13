#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> largest_dearrangement(vector<int> sequence){
    priority_queue<int> maxheap;

    int n = sequence.size();
    for(int v:sequence)
        maxheap.push(v);

    vector<int> result_sequence(n);
    int index=0;
    while(not maxheap.empty()){
        int max = maxheap.top();
        maxheap.pop();

        if(max != sequence[index] or maxheap.empty())
            result_sequence[index] = max;
        else{
            result_sequence[index] = maxheap.top();
            maxheap.pop();
            maxheap.push(max);
        }

        index++;
    }

    if(result_sequence.back() == sequence.back())
        swap(result_sequence[n-1],result_sequence[n-2]);

    return result_sequence;
}

int main()
{
    vector<int> seq = { 92, 3, 52, 13, 2, 31, 1 };
    vector<int> l_sequence = largest_dearrangement(seq);

    for(int v:l_sequence)
        cout<<v<<" ";
    cout<<endl;

    return 0;
}
