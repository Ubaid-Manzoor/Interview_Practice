// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}
// } Driver Code Ends

// ****************************************************************************************************
// ********************************************* MY CODE **********************************************
// ****************************************************************************************************

class Stack{
    int top=-1;
    char *arr;
public:
    Stack(int len){
        arr = new char[len];
    }

    void push(char c){
        arr[++top] = c;
    }

    char pop(){
        return arr[top--];
    }

    bool empty(){
        return top == -1;
    }
};

void reverse(char *str, int len){
    Stack stack(len);

    for(int i = 0 ; i < len ; i++){
        stack.push(str[i]);
    }

    int i = 0;
    while(not stack.empty()){
        str[i] = stack.pop();i++;
        cout<<str[i];
    }
    cout<<endl;
}










