// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

stack<int> deleteMid(stack<int>s,int sizeOfStack,int current);

int main() {
    int testcases;
    cin>>testcases;

    while(testcases--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;

        stack<int> myStack;

        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);


        }
        if(sizeOfStack==1)
        {
            cout<<myStack.top();
        }
        else
        {

            stack<int> modified=deleteMid(myStack,myStack.size(),0);


            while(!modified.empty())
            {
                cout<<modified.top()<<" ";
                modified.pop();
            }
        }
        cout<<endl;

    }
    return 0;
}// } Driver Code Ends


//User function Template for C++

//You need to complete this function



stack<int> deleteMid(stack<int>s,int sizeOfStack,int current){

    int top;
    if(current <= floor(sizeOfStack/2)){
        top = s.top();
        s.pop();
    }
    else
        return s;

    current++;
    s = deleteMid(s,sizeOfStack,current);
    current--;

    if(current != floor(sizeOfStack/2))
        s.emplace(top);

    return s;
}
