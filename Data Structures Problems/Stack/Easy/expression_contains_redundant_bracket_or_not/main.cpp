#include <iostream>
#include <stack>

using namespace std;


bool checkRedundancy(string &str){
    stack<char> st;

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] != ')'){
            st.emplace(str[i]);
        }else{
            bool operator_flag = true;

            int top = st.top();
            while(st.top() != '('){
                if(top == '*' or top == '-' or top == '+' or top == '/')
                    operator_flag = false;
                st.pop();
                top = st.top();
            }

            if(operator_flag)
                return false;

            st.pop();

        }
    }

    return true;
}

int main()
{
    string str = "((a+b))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "(a+(b)/c)";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "(a+b*(c-d))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "(b)";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "((a+b)*(c-d))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "(a+(b)*(c-d))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "((a)+(b)*(c))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    str = "(((a)))";
    checkRedundancy(str) ? cout<<"NO"<<endl : cout<<"YES"<<endl;

    return 0;
}
