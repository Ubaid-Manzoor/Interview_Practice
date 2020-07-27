#include <iostream>
#include <deque>
#include <limits>

using namespace std;

class Queue{
private:
    deque<int> dq;
public:
    void enqueue(int x){
        dq.emplace_back(x);
    }

    int dequeue(){
        if(not dq.empty()){
            int x = dq.front();
            dq.pop_front();
            return x;
        }
        return numeric_limits<int>::min();
    }

    void display(){
        for(int x:dq)
            cout<<x<<" ";
        cout<<endl;
    }
    int size(){
        return dq.size();
    }
};

class Stack{
private:
    deque<int> dq;
public:
    void push(int x){
        dq.emplace_back(x);
    }

    int pop(){
        if(not dq.empty()){
            int x = dq.back();
            dq.pop_back();
            return x;
        }
        return numeric_limits<int>::min();
    }
    void display(){
        for(int x:dq)
            cout<<x<<" ";
        cout<<endl;
    }

    int size(){
        return dq.size();
    }
};
int main()
{
    // object of Stack
    Stack stk;

    // push 7 and 8 at top of stack
    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    // pop an element
    stk.pop();
    cout << "Stack: ";
    stk.display();

    // object of Queue
    Queue que;

    // insert 12 and 13 in queue
    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    // delete an element from queue
    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}
