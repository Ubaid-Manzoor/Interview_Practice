#include <iostream>
#include <vector>

using namespace std;

void printSeqUtil(int n, int k, int value, vector<int> &result){
    if(result.size() == k){
        for(int x:result)
            cout<<x<<" ";
        cout<<endl;
        return;
    }

    if(value <= n){
        result.emplace_back(value);
        printSeqUtil(n, k, value + 1, result);

        result.pop_back();
        printSeqUtil(n, k, value + 1, result);
    }
}

void printSeq(int n, int k){
    vector<int> result;
    printSeqUtil(n, k, 1, result);
}

int main()
{
    int k = 3, n = 5;
    printSeq(n, k);
    return 0;
}
