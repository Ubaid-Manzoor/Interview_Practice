#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void first_not_second(vector<long long int> first_array, vector<long long int> second_array){
    unordered_set<long long int> hash;
    for(long long int value:second_array){
        if(hash.find(value) == hash.end()){
            hash.emplace(value);
        }
    }

    for(long long int value:first_array){
        if(hash.find(value) == hash.end())
            cout<<value<<" ";
    }

    cout<<endl;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int first_size,second_size;
        cin>>first_size>>second_size;
        for(int i = 0 ; i < first_size ; i++)
            cin>>first_size[i];
        for(int i = 0 ; i < second_size ; i++)
            cin>>second_size[i];
    }
}
