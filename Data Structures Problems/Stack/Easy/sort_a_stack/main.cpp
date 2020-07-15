// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
    stack<int> s;
    void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
    SortedStack *ss = new SortedStack();
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    int k;
    cin>>k;
    ss->s.push(k);
    }
    ss->sort();
    printStack(ss->s);
}
}// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void sortedInsert(stack<int> &s, int x){
    if(s.empty())
        s.emplace(x);
    else if(s.top() <= x){
        s.emplace(x);
    }else{
        int top = s.top();
        s.pop();
        sortedInsert(s, x);
        s.emplace(top);
    }
}

void sortStack(stack<int> &s){
    if(s.empty())
        return;

    int top = s.top();s.pop();

    sortStack(s);

    sortedInsert(s,top);
}



void SortedStack :: sort()
{
   sortStack(s);
}




















