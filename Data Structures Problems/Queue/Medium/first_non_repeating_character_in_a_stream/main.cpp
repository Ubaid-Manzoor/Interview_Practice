#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

void nonRepeatingChar(vector<char> stream){
    unordered_map<char,int> counter;
    queue<char> q;

    for(char bit:stream){
        if(counter.find(bit) == counter.end()){
            q.emplace(bit);
            counter[bit] = 0; //  0 means bit is non repeating
        }else{
            counter[bit] = 1; //  0 means bit is repeating
        }

        // Print the non repeating char
        while(not q.empty() and counter[q.front()] != 0){
            q.pop();
        }

        if(q.empty()){
            cout<<-1<<" ";
        }else{
            cout<<q.front()<<" ";
        }
    }
}


int main(){
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int stream_size;cin>>stream_size;

        vector<char> stream(stream_size);
        for(int j = 0 ; j < stream_size ;j++){
            cin>>stream[j];
        }

        nonRepeatingChar(stream);
        cout<<endl;
    }
}
