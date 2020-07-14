#include <iostream>
#include <stack>

using namespace std;

void next_greater_elements(long long int arr[], long long int n){
    stack<pair<long long int,long long int>> st;
    long long int next_greater[n];
    for(long long int i = 0 ; i < n ; i++)
        next_greater[i] = -1;

    st.emplace(make_pair(arr[0],0));

    for(long long int i = 1; i < n ; i++){
        if(st.empty()){
            st.emplace(make_pair(arr[i],i));
            continue;
        }
        if(st.top().first < arr[i]){
            while( (not st.empty()) and  st.top().first < arr[i] ){
                next_greater[st.top().second] = arr[i];
                st.pop();
            }
            st.emplace(make_pair(arr[i],i));
        }else{
            st.emplace(make_pair(arr[i],i));
        }
    }

    for(long long int i = 0 ; i < n ; i++)
        cout<<next_greater[i]<<" ";
    cout<<endl;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        long long int n;cin>>n;
        long long int arr[n];
        for(long long int j = 0 ; j < n ; j++)
            cin>>arr[j];
        next_greater_elements(arr, n);
    }
}
