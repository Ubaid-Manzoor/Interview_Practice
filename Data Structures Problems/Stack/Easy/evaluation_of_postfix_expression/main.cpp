#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
using namespace std;

bool is_operator(char o){
    if(o == '*' or o == '+' or o == '-' or o == '/')
        return true;
    return false;
}

int evaluvate(string postfix){
    stack<int> st;

    for(int i = 0; i < postfix.size() ; i++){
        if( is_operator(postfix[i]) ){
            int b = st.top();st.pop();
            int a = st.top();st.pop();
            switch(postfix[i]){
                case '+':
                    st.emplace(a + b);
                    break;
                case '-':
                    st.emplace(a - b);
                    break;
                case '*':
                    st.emplace(a * b);
                    break;
                case '/':
                    st.emplace(a / b);
                    break;
                default:
                    break;
            }
        }else{
            st.emplace(postfix[i] - '0');
        }
    }
    return st.top();
}


int main() {
    //code

    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string postfix;cin>>postfix;
        cout<<evaluvate(postfix)<<endl;
    }
    return 0;
}
