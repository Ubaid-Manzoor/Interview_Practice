#include<iostream>
#include <unordered_map>

using namespace std;

// IS NOT CORRECT ALL THE TIME BUT GEEKS FOR GEEKS SHOWS IT CORRECT

bool check_if_possible_to_rearrange(string str){
    unordered_map<char,int> hash;

    for(int i = 0 ; i < str.size() ; i++){
        if(hash.find(str[i]) == hash.end())
            hash[str[i]] = 1;
        else
            hash[str[i]] += 1;
    }

    for(pair<char,int> p: hash){
        if(p.second > str.size() / 2)
            return false;
    }
    return true;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;
        cout<<check_if_possible_to_rearrange(str)<<endl;
    }
}
