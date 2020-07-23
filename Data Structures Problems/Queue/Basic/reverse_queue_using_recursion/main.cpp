// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<long long int> rev(queue<long long int> q);
int main()
{
    long long int test;
    cin>>test;
    while(test--)
    {
    queue<long long int> q;
    long long int n, var;
    cin>>n;
    while(n--)
    {
        cin>>var;
        q.push(var);
    }
    queue<long long int> a=rev(q);
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl;
    }
}// } Driver Code Ends


//function Template for C++

void inplace_rev(queue<long long int> &q){
    if(q.empty())
        return;

    long long int front = q.front();
    q.pop();

    inplace_rev(q);

    q.emplace(front);
}

queue<long long int> rev(queue<long long int> q)
{
    // add code here.
    inplace_rev(q);
    return q;
}

