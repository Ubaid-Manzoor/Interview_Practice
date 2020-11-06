#include <iostream>
#include <stack>

using namespace std;


void printStack(stack<char> st){
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

void pushToBottom(stack<char> &st, char c){
    if(not st.empty()){
        char top = st.top();st.pop();
        pushToBottom(st, c);
        st.push(top);
    }else
        st.push(c);
}

void reverseStack(stack<char> &st){
    if(not st.empty()){
        char top = st.top();st.pop();
        reverseStack(st);
        pushToBottom(st, top);
    }
}

int main()
{

    // push elements into
    // the stack
    stack<char> st;
    st.push('1');
    st.push('2');
    st.push('3');
    st.push('4');
    st.push('5');

    printStack(st);

    reverseStack(st);
    cout<<"After Reversing"<<endl;

    printStack(st);

    return 0;
}
