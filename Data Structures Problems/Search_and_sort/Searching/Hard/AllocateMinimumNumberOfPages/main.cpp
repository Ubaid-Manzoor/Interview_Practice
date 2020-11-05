#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool checkIfValid(vector<long long int> &books, int nOfStudents, long long int maxPages){
    long long int currentSum = 0;
    int doneStudents = 1;

    for(int i = 0 ; i < books.size() ; i++){

        if(maxPages < books[i])
            return false;

        if(currentSum + books[i] > maxPages){
            currentSum = books[i];
            doneStudents++;
            if(doneStudents > nOfStudents)
                return false;
        }else
            currentSum += books[i];
    }
    return true;
}

long long int MinimumMaxPages(vector<long long int> &books, int nOfStudents){
    if(nOfStudents > books.size())
        return -1;
    long long int l = 0;
    long long int r=0;
    for(long long int b:books)
        r+= b;

    long long int mid;long long int ans=r;
    while(r >= l){
        mid = l + (r - l)/2;
        if(checkIfValid(books, nOfStudents, mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }

    return ans;
}

int main(){
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        long long int N;cin>>N;
        vector<long long int> books(N);

        for(int b = 0 ; b < N ; b++)
            cin>>books[b];

        int nOfStudents;cin>>nOfStudents;

        cout<<MinimumMaxPages(books, nOfStudents)<<endl;
    }
}
