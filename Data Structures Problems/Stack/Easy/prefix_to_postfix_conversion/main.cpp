#include <iostream>
#include <stack>

using namespace std;


string toPostfix(string prefix){
    stack<string> st;

    for(int i = prefix.size() - 1 ; i >= 0 ; i--){
        char current = prefix[i];
        if(current == '+' or current == '-' or current == '*' or current == '/'){
            string op1 = st.top();st.pop();
            string op2 = st.top();st.pop();
            st.emplace(op1 + op2 + current);
        }else
            st.emplace(string(1,current));
    }

    return st.top();
}

int main(){
    string prefix = "*+AB-CD";
    cout<<toPostfix(prefix)<<endl;
}
