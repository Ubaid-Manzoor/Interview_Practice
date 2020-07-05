#include <iostream>
#include <unordered_set>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/remove-all-duplicates-from-a-given-string/0


// Time Complexity O
string remove_duplicates(string str){
    string new_string;
    unordered_set<char> char_set;
    for(int i = 0 ; i < str.size() ; i++){
        if(char_set.find(str[i]) == char_set.end()){
            new_string += str[i];
            char_set.emplace(str[i]);
        }
    }
    return new_string;
}


int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        string str;cin>>str;
        cout<<remove_duplicates(str)<<endl;
    }
}
