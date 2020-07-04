#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool are_equal(unordered_map<char,int> hash1,unordered_map<char,int> hash2){
    for(auto it1 = hash1.begin(),it2 = hash2.begin(); it1 != hash1.end() ;it1++,it2++){
        if(it1->second != it2->second)
            return false;
    }
    return true;
}

int count_occurences(string &str, string &to_match){
    // Create a counter
    unordered_map<char,int> phase,hash;
    for(int i = 0 ; i < str.size() ; i++){
            phase[str[i]] = 0;
            hash[str[i]] = 0;
            if(i < to_match.size()){
                phase[to_match[i]] = 0;
                hash[to_match[i]] = 0;
            }
    }



    for(int i = 0 ; i < to_match.size() ; i++)
            phase[to_match[i]] += 1;


    for(int i = 0 ; i < to_match.size(); i++)
        hash[str[i]] += 1;

    int count = 0;
    if(are_equal(phase,hash))
        count++;


    for(int left=1,right=to_match.size() ; right < str.size() ; left++,right++){
            hash[str[left-1]]--;
            hash[str[right]]++;
            if(are_equal(phase,hash)){
                count++;
            }
    }
    cout<<count<<endl;

}


int main(){
    int tc;
    cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;
        cin>>str;
        string to_match;
        cin>>to_match;
        count_occurences(str,to_match);
    }
}



