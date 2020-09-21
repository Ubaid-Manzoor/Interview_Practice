#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;


bool isPairWithDiff(vector<vector<int>> max, int k){
    unordered_set<int> hashset;
    for(auto vec:max)
        for(int v:vec)
            hashset.emplace(v);

    for(auto vec:max)
        for(int v: vec)
            if(hashset.count(k + v) == 1)
                return true;
    return false;
}

int main()
{

    // Input matrix
    vector<vector<int>> mat = { { 5, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 70 } };

    // given difference
    int k = 85;

    if (isPairWithDiff(mat ,k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
