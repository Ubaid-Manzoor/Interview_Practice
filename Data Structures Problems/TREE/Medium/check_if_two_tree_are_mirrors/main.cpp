#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool check_mirrorUtil(vector<stack<int>> s, vector<queue<int>> q){
    if(s.size() != q.size())
        return false;

    for(int i = 0 ; i < s.size(); i++){
        while(not s[i].empty()){
            if(s[i].top() != q[i].front()){
                return false;
            }else{
                s[i].pop();q[i].pop();
            }
        }
    }

    return true;
}

bool check_mirror(vector<pair<int,int>> edges1, vector<pair<int,int>> edges2, int n){
    vector<stack<int>> s(n);
    vector<queue<int>> q(n);


    for(int i = 0 ; i < edges1.size() ; i++){
        pair<int,int> current_edges = edges1[i];
        s[current_edges.first].emplace(current_edges.second);
    }

    for(int i = 0 ; i < edges2.size() ; i++){
        pair<int,int> current_edges = edges2[i];
        q[current_edges.first].emplace(current_edges.second);
    }

    return check_mirrorUtil(s,q);
}

int main(){
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n, e;
        cin>>n>>e;
        vector<pair<int,int>> edges1,edges2;
        for(int j = 0 ; j < e ; j++){
            int start,end;
            cin>>start>>end;
            edges1.emplace_back(make_pair(start,end));
        }
        for(int j = 0 ; j < e ; j++){
            int start,end;
            cin>>start>>end;
            edges2.emplace_back(make_pair(start,end));
        }

        cout<<check_mirror(edges1, edges2, n)<<endl;
    }
}
