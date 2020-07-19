#include <iostream>
#include <stack>

using namespace std;


string decode(string encoded_str){
    stack<int> integerStack;
    stack<char> characterStack;
    string temp="", result="";

    for(int i = 0 ; i < encoded_str.size() ; i++){
        int count = 0;
        if(encoded_str[i] >= '0' and encoded_str[i] <= '9'){ //  IF WE ENCOUNTER A NUMBER
            while(encoded_str[i] >= '0' and encoded_str[i] <= '9'){
                count = count * 10 + (encoded_str[i] - '0');
                i++;
            }
            i--;
            integerStack.emplace(count);
        }else if(encoded_str[i] == ']'){ // WHEN WE ENCOUNTER A CLOSE BRACKET
            temp = "";
            while(characterStack.top() != '['){
                temp = characterStack.top() + temp;
                characterStack.pop();
            }
            characterStack.pop();

            int times = integerStack.top();integerStack.pop();
            for(int j = 0 ; j < times ; j++)
                for(int k = 0 ; k < temp.size() ;k++)
                    characterStack.emplace(temp[k]);
        }else
            characterStack.emplace(encoded_str[i]);  // OTHERWISE JUST PUSH INTO THE STACK
    }

    while(not characterStack.empty()){
        result = characterStack.top() + result;
        characterStack.pop();
    }

    return result;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        string encoded_str;cin>>encoded_str;
        cout<<decode(encoded_str)<<endl;
    }
}
