#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>

using namespace std;

string removeDuplicateWord(string str){
    stringstream ss(str);

    unordered_set<string> hashstr;

    string word;
    string result_string="";
    while(ss >> word){
        if(hashstr.find(word) == hashstr.end()){
            if(result_string != "")
                result_string += " ";
            result_string += word;
            hashstr.emplace(word);
        }
    }

    return result_string;
}

int main()
{
    string str = "Geeks for Geeks A Computer"
                " Science portal for Geeks";
    string newString = removeDuplicateWord(str);

    cout<<newString<<endl;
    return 0;
}
