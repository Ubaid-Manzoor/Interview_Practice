#include <iostream>
#include <queue>
using namespace std;


void firstNegativeInWindowOfK(int arr[],int n, int k){
    queue<int> q;

    int i;
    for(i = 0 ; i < k ; i++)
        if(arr[i] < 0)
            q.emplace(i);


    while(i < n){
        if(not q.empty())
            cout<<arr[q.front()]<<" ";
        else
            cout<<"0"<<" ";

        if(not q.empty() and q.front() <= i - k){
            q.pop();
        }

        if(arr[i] < 0){
            q.emplace(i);
        }

        i++;
    }

    if(not q.empty())
        cout<<q.front()<<endl;
    else
        cout<<"0"<<endl;

}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int n;cin>>n;

        int arr[n];
        for(int j = 0 ; j < n ; j++)
            cin>>arr[j];
        int k;cin>>k;

        firstNegativeInWindowOfK(arr, n, k);
    }
}
