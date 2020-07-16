#include <iostream>
#include <stack>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/valid-substring/0


// solution using O(n) space
int smallest_valid_substring(string str){
    stack<int> st;

    int result;
    st.emplace(-1);
    for(int i = 0 ; i < str.size(); i++){
        if(str[i] == '('){
            st.emplace(i);
        }else{
            st.pop();
            if(st.empty())
                st.emplace(i);
            else
                result = max(i - st.top(), result);
        }
    }

    return result;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;
        cout<<smallest_valid_substring(str)<<endl;
    }
}
