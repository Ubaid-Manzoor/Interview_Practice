#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool isValid(int ranking[], int nOfCooks, int pratas, int minTime){

    int pratasCooked=0;
    for(int c = 0 ; c < nOfCooks; c++){
        int r = ranking[c];
        int k = 1;
        int time = minTime;
        while(time > 0){
            time -= r * k;
            if(time >= 0)
                pratasCooked++;
            k++;
            if(pratasCooked == pratas)
                return true;
        }
    }

    return false;
}

int minimumTimeToCook(int pratas, int ranking[], int nOfCooks){
    sort(ranking, ranking + nOfCooks);
    int l = 1;
    int r = ceil(pratas/2.0) * (ranking[0] + pratas * ranking[0]);

    int mid; int ans;

    while(r >= l){
        mid = l + (r - l)/2;
        cout<<l<<" "<<r<<" "<<mid<<endl;
        if(isValid(ranking, nOfCooks ,pratas, mid)){
            ans = mid;
            r = mid - 1;
        }else
            l = mid + 1;
    }

    return ans;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int pratas;cin>>pratas;
        int nOfCooks;cin>>nOfCooks;
        int ranking[nOfCooks];
        for(int c = 0 ; c < nOfCooks ; c++)
            cin>>ranking[c];

        cout<<minimumTimeToCook(pratas, ranking, nOfCooks)<<endl;
    }
}
