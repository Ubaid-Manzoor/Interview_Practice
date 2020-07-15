// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

stack<int>_push(int arr[],int n);

void _getMinAtPop(stack<int>s);

 // } Driver Code Ends


//User function Template for C++

/* inserts elements of the array into
   stack and return the stack
*/
stack<int> _push(int arr[],int n)
{
   // your code here
   stack<int> st;
   for(int i = 0 ; i < n ;i++){
       if(st.empty()){
           st.emplace(arr[i]);
       }else if(st.top() > arr[i]){
           st.emplace(arr[i]);
       }else{
           st.emplace(st.top());
       }
   }
   return st;
}

/* print minimum element of the stack each time
   after popping
*/
void _getMinAtPop(stack<int>st)
{
    // your code here
    while(not st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        stack<int>mys=_push(arr,n);
        _getMinAtPop(mys);
        cout<<endl;



    }
    return 0;
}

  // } Driver Code Ends
