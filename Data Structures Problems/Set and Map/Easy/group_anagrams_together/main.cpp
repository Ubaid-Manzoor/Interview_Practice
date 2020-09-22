#include <bits/stdc++.h>
#include <iostream>

using namespace std;


unordered_map<string,int> groupCount(vector<string> words){
    unordered_map<string, int> groups;
    for(string word: words){
        sort(word.begin(), word.end());

        if(groups.count(word) == 0)
            groups[word] = 1;
        else
            groups[word] += 1;
    }

    return groups;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        vector<string> words(n);

        for(int j = 0 ; j < n ; j++){
            cin>>words[j];
        }

        unordered_map<string,int> groupSize = groupCount(words);
        for(pair<string,int> p: groupSize)
            cout<<p.second<<" ";

        cout<<endl;
    }
}
