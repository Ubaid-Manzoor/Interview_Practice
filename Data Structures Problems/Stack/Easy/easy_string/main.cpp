#include <iostream>
#include<bits/stdc++.h>
using namespace std;


void compress(string str){
    stack<char> st;

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    int count=0;

    for(int i = 0 ; i < str.size() ; i++){
        if(st.empty()){
            st.emplace(str[i]);
        }else if( st.top() != str[i] ){
            cout<<count<<st.top();
            st.emplace(str[i]);
            count=0;
        }
        count++;
    }
    cout<<count<<st.top()<<endl;
}

int main() {
    int tc;cin>>tc;
    for(int i = 0 ;i < tc; i++){
        string str;cin>>str;
        compress(str);
    }
    return 0;
}
