#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int max_area(vector<int> histogram){
    stack<int> st;

    st.emplace(histogram[0]);
    for(int i = 1 ; i < histogram.size() ;i++){
        if(st.top() > histogram[i]){

        }
    }

}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int n;cin>>n;
        vector<int> arr(n);
        for(int j = 0 ; j < n ;j++)
            cin>>arr[i];

        cout<<max_area(arr);
    }
    return 0;
}
