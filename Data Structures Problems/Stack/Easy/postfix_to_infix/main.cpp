#include <iostream>
#include <stack>

using namespace std;

string getInfix(string exp){
    stack<string> st;

    for(int i = 0 ; i < exp.size() ; i++){
        char current = exp[i];
        if(current == '+' or current == '-' or current == '*' or current == '/'){
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            st.emplace("(" + op1 + current + op2 + ")");
        }else{
            string current_str = string(1,current);
            st.emplace(current_str);
        }
    }

    return st.top();
}

int main()
{

    string exp = "ab*c+";
    cout<< getInfix(exp) <<endl;
    return 0;
}
