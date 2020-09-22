#include <bits/stdc++.h>
#include <iostream>

using namespace std;

bool canBePalindrome(string str){
    unordered_map<char,int> char_frequencies;

    for(char c:str)
        ++char_frequencies[c];

    int odd_frequency_count = 0;
    for(pair<char,int> p: char_frequencies){
        if( (p.second % 2) and ++odd_frequency_count > 1 )
            return false;
    }

    return true;
}

int main()
{
    string str="edified";

    if(canBePalindrome(str))
        cout<<"Yes we can"<<endl;
    else
        cout<<"No we can't";
}
