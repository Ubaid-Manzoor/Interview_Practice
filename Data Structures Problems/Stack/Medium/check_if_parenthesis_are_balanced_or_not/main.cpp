#include <iostream>
#include <stack>

using namespace std;

bool check_is_balanced(string arr){
    stack<char> stack;
    for(int i = 0 ; i < arr.size() ; i++){
        if(arr[i] == '{' || arr[i] == '(' || arr[i] == '['){
            stack.push(arr[i]);
            continue;
        }

        if(stack.empty())
            return false;

        char c = arr[i];
        const char p = stack.top();
        switch (c) {
        case '}':
            if(p == '{')
                stack.pop();
            else
                return false;
            break;
        case ')':
            if(p == '(')
                stack.pop();
            else
                return false;
            break;
        case ']':
            if(p == '[')
                stack.pop();
            else
                return false;
            break;
        default:
            break;
        }

    }
    return stack.empty();
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string arr;cin>>arr;
        if(check_is_balanced(arr))
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;
    }
}
