#include <iostream>
#include <stack>

using namespace std;

string toPrefix(string postfix){
    stack<string> st;

    for(int i = 0 ; i < postfix.size() ; i++){
        char current = postfix[i];
        if(current == '+' or current == '-' or current == '*' or current == '/'){
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            st.emplace(current + op1 + op2);
        }else
            st.emplace(string(1,current));
    }

    return st.top();
}

int main(){
//    string postfix = "AB+CD-*";
    string postfix = "ABC/-AK/L-*";

    cout<<toPrefix(postfix)<<endl;
}
