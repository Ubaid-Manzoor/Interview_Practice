#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int countWaysUtil(int x, int n,int num){
    int new_x = x - pow(num, n);
    if(new_x == 0)
        return 1;
    if(new_x < 0)
        return 0;

    return  countWaysUtil(new_x, n, num + 1) + countWaysUtil(x, n, num + 1);
}

int countWays(int x, int n){
    return countWaysUtil(x, n, 1);
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int x,n;cin>>x>>n;

        cout<<countWays(x, n)<<endl;
    }
}
