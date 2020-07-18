#include <iostream>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;



string to_postfix(string infix){
    string postfix="";
    stack<char> st;

    unordered_map<char,int> priority;
    priority['+'] = 1;
    priority['-'] = 1;
    priority['*'] = 2;
    priority['/'] = 2;
    priority['^'] = 3;

    unordered_set<char> brackets;
    brackets.emplace('(');
    brackets.emplace(')');
    brackets.emplace('{');
    brackets.emplace('}');
    brackets.emplace('[');
    brackets.emplace(']');

    for(int i = 0 ; i < infix.size() ; i++){
        if(priority.find(infix[i]) == priority.end() and brackets.find(infix[i]) == brackets.end() ){
            postfix += infix[i];
        }else{
            if(st.empty())
                st.emplace(infix[i]);
            else{
                if(priority.find(infix[i]) != priority.end() ){ //  IS AN OPERATOR
                    if(brackets.find(st.top()) == brackets.end()){ // Open Bracket is not at top of stack
                        while(not st.empty() and infix[i] != '(' and priority[st.top()] >= priority[infix[i]]){
                            postfix += st.top();st.pop();
                        }
                        st.emplace(infix[i]);
                    }else
                        st.emplace(infix[i]);
                }else{                                          // IS A BRACKET
                    if(infix[i] == '(' or infix[i] == '[' or infix[i] == '{'){
                        st.emplace(infix[i]);
                    }else{                                      // Closing Bracket
                        while(st.top() != '(' and st.top() != '[' and st.top() != '{'){
                            postfix += st.top();st.pop();
                        }
                        st.pop();
                    }
                }
            }
        }
    }

    while(not st.empty()){
        postfix += st.top();st.pop();
    }

    return postfix;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string infix;cin>>infix;
        cout<<to_postfix(infix)<<endl;
    }
}
