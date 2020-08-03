#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Char{
    char c;
    int count;

    Char(char c, int count){
        this->c = c;
        this->count = count;
    }
};

struct Compare {
    bool operator()(Char &lhs, Char &rhs) {
        return lhs.count < rhs.count;
    }
};

int minimun_square_sum(string str, int k){
    unordered_map<char,int> counter;
    priority_queue<Char, vector<Char>, Compare> p_q;

    for(int i = 0 ; i < str.size() ; i++){
        if(counter.find(str[i]) == counter.end())
            counter[str[i]] = 1;
        else
            counter[str[i]] += 1;
    }

    for(pair<char,int> p:counter){
        p_q.emplace(Char(p.first,p.second));
    }

    for(int i = 0 ; i < k ; i++){
        Char top = p_q.top();
        counter[top.c] -= 1;top.count--;

        p_q.pop();
        if(top.count != 0)
            p_q.emplace(top);
    }


    int square_sum=0;
    for(pair<char,int> p:counter){

        square_sum += p.second * p.second;
    }

    return square_sum;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;
        int k;cin>>k;
        cout<<minimun_square_sum(str,k)<<endl;
    }
}
