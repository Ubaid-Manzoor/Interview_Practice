#include <bits/stdc++.h>
using namespace std;

// Function to return the count of valid strings
int countStrings(int n, int m, string s[]){
    unordered_set<int> hashset;

    for(int col = 0 ; col < m ; col++){
        int mx=0;
        for(int row = 0 ; row < n ; row++)
            mx = max(mx, s[row][col] - '0');

        for(int row = 0 ; row < n ; row++)
            if(s[row][col] - '0' == mx)
                hashset.emplace(row);
    }

    return hashset.size();
}

// Driver code
int main()
{
//    string s[] = { "223", "232", "112" };
    string s[] = {"999", "122", "111"};
    int m = s[0].length();
    int n = sizeof(s) / sizeof(s[0]);
    cout << countStrings(n, m, s)<<endl;
}
