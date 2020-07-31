#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interLeaveQueue(queue<int> &q){
    stack<int> st;
    int n = q.size();

    while(q.size() > n/2){
        st.emplace(q.front());q.pop();
    }

    while(q.size() != n){
        q.emplace(st.top());st.pop();
    }


    int times = n;
    while(times > n/2){
        q.emplace(q.front());q.pop();
        times--;
    }

    while(q.size() > n/2){
        st.emplace(q.front());q.pop();
    }


    while(not st.empty()){
        q.emplace(st.top());st.pop();
        q.emplace(q.front());q.pop();
    }
}

int main(){
    queue<int> q;
        q.push(11);
        q.push(12);
        q.push(13);
        q.push(14);
        q.push(15);
        q.push(16);
        q.push(17);
        q.push(18);
        q.push(19);
        q.push(20);
        interLeaveQueue(q);
        int length = q.size();
        for (int i = 0; i < length; i++) {
            cout << q.front() << " ";
            q.pop();
        }
        return 0;
}
