#include <iostream>
#include <stack>

using namespace std;

int missing_braces(string str){
    if(str.size() % 2 != 0)
        return -1;

    stack<int> st;
    int count=0;

    for(int i = 0 ; i < str.size() ; i++){
        if(st.empty())
            st.emplace(str[i]);
        else if(st.top() == '{'){
            if(str[i] == '}') //  " { } " x
                st.pop();
            else
                st.emplace('{'); //  " { { "
        }else{ // " } "
            if(str[i] == '}'){ //  " } } " x
                st.pop();
                count += 1;
            }else
                st.emplace('{'); //  " } { "
        }
    }

    while(not st.empty()){
        int top = st.top();
        st.pop();

        if(top == '{' and st.top() == '{')
            count += 1;
        else
            count += 2;
        st.pop();
    }

    return count;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;
        cout<<missing_braces(str)<<endl;
    }
}
