#include<iostream>
#include <unordered_map>
#include <queue>

using namespace std;

bool check_if_possible_to_rearrange(string str){
    unordered_map<char,int> hash;
    for(char c:str){
        if(hash.find(c) == hash.end())
            hash[c] = 1;
        else
            hash[c] += 1;
    }

    priority_queue<pair<int,char> , vector<pair<int,char>> , less<pair<int,char>>> maxheap;

    for(pair<char,int> p:hash)
        maxheap.push(make_pair(p.second,p.first));


    pair<int,char> prev={-1, '0'};

    string result_str="";
    while(not maxheap.empty()){
        pair<int,char> top = maxheap.top();
        maxheap.pop();

        result_str.push_back(top.second);
        if(prev.first >= 1)
            maxheap.push(prev);

        top.first -= 1;
        prev = top;
    }

    if(result_str.length() == str.length())
        return true;
    else
        return false;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;
        cout<<check_if_possible_to_rearrange(str)<<endl;
    }
}
