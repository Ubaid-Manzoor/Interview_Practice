#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool check_if_anagram(string str1,string str2){
    if(str1.size() != str2.size()) return false;
    unordered_map<char,int> count;
    for(int i = 0 ; i < str1.size() ; i++){
        if(count.find(str1[i]) == count.end())
            count[str1[i]] = 1;
        else
            count[str1[i]] += 1;
    }

    for(int i = 0 ; i < str2.size() ; i++){
        if(count.find(str2[i]) == count.end())
            return false;
        else
            count[str2[i]] -= 1;
    }


    // CHECK
    for(pair<char,int> p:count){
        if(p.second != 0)
            return false;
    }

    return true;
}

int main()
{
    int tc;cin>>tc;
    for(int i ; i < tc; i++){
        string str1,str2;
        cin>>str1;cin>>str2;

        if(check_if_anagram(str1,str2))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
}
