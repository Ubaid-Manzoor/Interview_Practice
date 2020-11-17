#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

    void NBitBinaryHelper(int N, string ans, int ones, int zeroes, vector<string> &result){
        if(zeroes > ones)
            return;
        if(ans.size() == N){
            result.emplace_back(ans);
            return;
        }

        NBitBinaryHelper(N, ans + "1", ones + 1, zeroes, result);
        NBitBinaryHelper(N, ans + "0", ones, zeroes + 1, result);
    }

    vector<string> NBitBinary(int N)
    {
        vector<string> result;
        result.reserve(pow(2,N));
        NBitBinaryHelper(N, "", 0, 0, result);
        return result;
    }
};


int main()
{


    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.NBitBinary(n);

        for(auto i:ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
