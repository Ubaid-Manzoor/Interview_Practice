#include <iostream>
#include <unordered_set>
using namespace std;

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
    string str = "geeksforgeeks";
    cout<<remove_duplicates(str)<<endl;
}
