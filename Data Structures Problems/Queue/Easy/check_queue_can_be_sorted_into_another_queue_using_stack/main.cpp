#include <iostream>
#include <queue>
#include <stack>

using namespace std;

void display(queue<int> q){
    while(not q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

bool checkSorted(int n, queue<int> q){
    stack<int> st;
    queue<int> s_q;

    int current_expected = 1;

    while(current_expected <= n){
        if(not q.empty() and q.front() == current_expected){
            s_q.emplace(q.front());q.pop();
        }else if(not st.empty() and st.top() == current_expected){
            s_q.emplace(st.top());st.pop();
        }else{
            if(q.empty())
                return false;

            while(q.front() != current_expected){
                st.emplace(q.front());
                q.pop();
            }

            if(q.empty())
                return false;

            s_q.emplace(q.front());
            q.pop();
        }
        current_expected++;
    }

    display(s_q);
    return true;
}

int main(){
    queue<int> q;

//    q.push(10);
//    q.push(1);
//    q.push(9);
//    q.push(8);
//    q.push(7);
//    q.push(2);
//    q.push(3);
//    q.push(4);
//    q.push(5);
//    q.push(6);

    q.push(5);
    q.push(1);
    q.push(2);
    q.push(6);
    q.push(3);
    q.push(4);

    int n = q.size();

    (checkSorted(n,q) ? (cout << "Yes") :
                         (cout << "No"));
    cout<<endl;
//    cout<<checkSorted(n,q)<<endl;
    return 0;
}
