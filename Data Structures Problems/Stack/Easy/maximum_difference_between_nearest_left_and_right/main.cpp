// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/maximum-difference/1


int findMaxDiff(int [], int n);

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<findMaxDiff(a,n)<<endl;
   }
    return 0;
}


// } Driver Code Ends


/*You are required to complete this method */
int findMaxDiff(int A[], int n){
    stack<int> st_1,st_2;
    vector<int> left(n),right(n);


    st_1.emplace(0);
    for(int i = 0 ; i < n ; i++){
        while(st_1.top() >= A[i])
            st_1.pop();

        left[i] = st_1.top();
        st_1.emplace(A[i]);
    }

    st_2.emplace(0);
    for(int i = n-1 ; i >= 0 ; i--){
        while(st_2.top() >= A[i])
            st_2.pop();

        right[i] = st_2.top();
        st_2.emplace(A[i]);
    }

    int result = 0;
    for(int i = 0 ; i < n ; i++)
        result = max(abs(left[i]-right[i]),result);

    return result;
}



















