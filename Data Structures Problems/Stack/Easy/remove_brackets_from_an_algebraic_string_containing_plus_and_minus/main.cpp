#include <iostream>
#include <stack>

using namespace std;

string simplify(string expression){
//    stack<char> st;
    string result="";
    stack<char> sign;
    sign.emplace('+');

    for(int i = 0 ; i < expression.size() ; i++){
        char current = expression[i];

        if(current == '(')
            sign.emplace(result[result.size()-1]);
        else if(current == ')')
            sign.pop();
        else{
            if(current == '-' or current == '+'){
                if(current != sign.top()){
                    result += '-';
                }else{
                    result += '+';
                }
            }else{
                result += current;
            }
        }
    }


    return result;
}


int main(){
    string s1 = "a-(b)+c";
//    string s2 = "a-(b-c-(d+e))-f";
    string s2 = "a-(b-c-(d+e)-(a-b+c-d+(a-b-(a-g))))-f";
    cout << simplify(s1) << endl;
    cout << simplify(s2) << endl;
    return 0;
}

