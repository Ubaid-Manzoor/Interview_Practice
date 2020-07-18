#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int after_manupilation(vector<string> sentance){
    stack<string> st;

    int result = sentance.size();
    for(int i = 0 ; i < sentance.size() ; i++){
        if(st.empty()){
            st.emplace(sentance[i]);
        }else{
            if(st.top() == sentance[i]){
                st.pop();
                result -= 2;
            }else{
                st.emplace(sentance[i]);
            }
        }
    }

    return result;
}

int main() {
    //code
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int n;cin>>n;
        vector<string> sentance(n);
        for(int j = 0 ; j < n ;j++){
            cin>>sentance[j];
        }
        cout<<after_manupilation(sentance)<<endl;
    }
    return 0;
}
