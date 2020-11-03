#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

bool isValid(ll trees[], ll N, ll M, int height){
    int woodChopped=0;

    for(int t = 0 ; t < N ; t++){
        woodChopped += (trees[t] - height) > 0 ? (trees[t] - height) : 0 ;
        if(woodChopped >= M)
            return true;
    }

    return false;
}

ll maximumIntegerHeight(ll trees[], ll N, ll M){
    ll l =  1;
    ll r = *max_element(trees, trees + N);

    ll mid;ll ans;
    while(r >= l){
        mid = l + (r - l)/2;

        if(isValid(trees, N, M, mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    return ans;
}

int main(){
    ll N,M;cin>>N>>M;

    ll trees[N];

    for(int i = 0 ; i < N ; i++)
        cin>>trees[i];


    cout<<maximumIntegerHeight(trees, N, M);
}
