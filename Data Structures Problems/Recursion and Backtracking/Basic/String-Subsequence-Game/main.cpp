#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool isVowel(char v){
    unordered_set<char> vowels = {'a','e','i','o','u'};
    if(vowels.find(v) != vowels.end())
        return true;
    return false;
}

void printSubsequence(string input, set<string> &result, int currentIndex=0, string output=""){
    if(currentIndex >= input.size()){
        if(isVowel(output[0]) and not isVowel(output.back())){
            result.insert(output);
        }
        return;
    }

    printSubsequence(input, result, currentIndex + 1, output + input[currentIndex]);
    printSubsequence(input, result, currentIndex + 1,output);
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        string input;cin>>input;

        set<string> result;
        printSubsequence(input, result);
        if(result.size() == 0)
            cout<<"-1"<<endl;
        else{
            for(string s: result){
                cout<<s<<" ";
            }
            cout<<endl;
        }
    }
}
