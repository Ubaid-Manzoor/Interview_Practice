#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkIfValid(vector<long long int> &coordinates, int numberOfCows, long long int gap){

    int prev=coordinates.front();
    numberOfCows--;
    for(int c = 1 ; c < coordinates.size() ; c++){
        int C = coordinates[c];

        if(C - prev >= gap){
            numberOfCows--;
            if(numberOfCows == 0)
                return true;
            prev = C;
        }
    }
    if(numberOfCows)
        return false;
}

void binarySearch(vector<long long int> &coordinates,long long int l, long long int r, int cows, long long int &ans){
    if(l > r)
        return;

    long long int mid = l + (r - l)/2;
    if(checkIfValid(coordinates, cows, mid)){
        ans = mid;
        binarySearch(coordinates, mid + 1, r, cows, ans);
    }else
        binarySearch(coordinates, l, mid - 1, cows, ans);
}


int largestMinimumDistance(vector<long long int> coordinates, int cows){
    sort(coordinates.begin(), coordinates.end());

    long long int minDis = 0;
    long long int maxDis = coordinates.back() - coordinates.front();

    long long int ans;
    binarySearch(coordinates, minDis, maxDis, cows, ans);

    return ans;
}

int main(){
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int N,C;cin>>N>>C; // N -> number of stalls, C -> number of cows
        vector<long long int> coordinates(N);
        for(int c = 0 ; c < N ; c++)
            cin>>coordinates[c];

        cout<<largestMinimumDistance(coordinates, C)<<endl;
    }
}
