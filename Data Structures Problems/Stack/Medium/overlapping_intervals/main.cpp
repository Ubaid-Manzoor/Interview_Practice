#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.first < p2.first;
}


void print_stack(stack<pair<int,int>> &st){
    if(st.empty())
        return;

    pair<int,int> top = st.top();
    st.pop();
    print_stack(st);

    cout<<top.first<<" "<<top.second<<" ";
}

void overlap_interval(vector<pair<int,int>> intervals){
    stack<pair<int,int>> st;

    sort(intervals.begin(), intervals.end(), compare);

    for(int i = 0 ; i < intervals.size() ; i++){
        if(not st.empty() and st.top().second >= intervals[i].first){
            if(st.top().second < intervals[i].second){
                pair<int,int> inter = st.top();
                st.pop();
                st.emplace(make_pair(inter.first,intervals[i].second));
            }
        }else
            st.emplace(intervals[i]);
    }

    print_stack(st);
    cout<<endl;
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int intervals;cin>>intervals;
        vector<pair<int,int>> arr;
        for(int j = 0 ; j < intervals ; j++){
            int start,end;cin>>start>>end;
            arr.emplace_back(make_pair(start,end));
        }
        overlap_interval(arr);
    }
}
