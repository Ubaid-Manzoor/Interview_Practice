#include <iostream>
#include <stack>
#include <tuple>

using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/print-bracket-number/0


// We can also only print the number instead of storing the number
void print_bracker_number(string arr){
    stack<tuple<char,int,int>> st;

    int number_arr[arr.size()];
    int index=0;
    int bracket_number=1;

    for(int i = 0  ; i < arr.size() ; i++){
        if(arr[i] == '('){
            st.emplace(make_tuple('(',bracket_number,index));
            bracket_number++;index++;
        }else if(arr[i] == ')'){
            tuple<char,int,int> top = st.top();
            if(get<0>(top) == '('){
                number_arr[get<2>(top)] = get<1>(top);
                number_arr[index] = get<1>(top);
                st.pop();
            }
            index++;
        }

    }

    while(not st.empty()){
        tuple<char,int,int> top = st.top();
        number_arr[get<2>(top)] = get<1>(top);
        st.pop();
    }

    for(int i = 0 ; i < index ; i++)
        cout<<number_arr[i]<<" ";
    cout<<endl;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        string arr;cin>>arr;
        print_bracker_number(arr);
    }
}
