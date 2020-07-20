#include <iostream>
#include <string>
#include <stack>

using namespace std;

string toInfix(string prefix){
    stack<string> st;

    for(int i = prefix.size()-1 ; i >=0 ; i--){
        char current = prefix[i];
        if(current == '+' or current == '-' or current == '*' or current == '/' ){
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();

            st.emplace("(" + op1 + current + op2 + ")");
        }else{
            st.emplace(string(1,current));
        }
    }

    return st.top();
}

int main(){
    string prefix = "*-A/BC-/AKL";
    cout<<toInfix(prefix)<<endl;
}
