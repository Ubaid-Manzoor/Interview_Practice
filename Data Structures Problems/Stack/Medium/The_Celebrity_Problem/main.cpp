// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n){
    stack<int> st;

    for(int i = 0 ; i < n ;i++)
        st.emplace(i);

    while(st.size() > 1){
        int guest1 = st.top();st.pop();
        int guest2 = st.top();st.pop();

        if(M[guest1][guest2] == 1 and M[guest2][guest1] == 0)
            st.emplace(guest2);
        else if(M[guest2][guest1] == 1 and M[guest1][guest2] == 0)
            st.emplace(guest1);
    }
    int candidate;
    if(not st.empty())
        candidate = st.top();
    else
        return -1;

    for(int i = 0 ; i < n ;i++){
        if(i != candidate and (M[candidate][i] != 0 or M[i][candidate] != 1) )
            return -1;
    }

    return candidate;
}
























