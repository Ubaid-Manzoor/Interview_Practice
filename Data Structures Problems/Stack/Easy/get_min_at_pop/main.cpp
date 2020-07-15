// { Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a;
        cin>>n;
        while(!isEmpty()){
            pop();
        }
        while(!isFull(n)){
            cin>>a;
            push(a);
        }
        cout<<getMin()<<endl;
    }
}// } Driver Code Ends


stack<int> min_s;

/*Complete the function(s) below*/
void push(int a)
{
     //add code here.
    s.emplace(a);

    if(not min_s.empty())
        a = min(min_s.top(),a);
    min_s.emplace(a);
}

bool isFull(int n)
{
     //add code here.
    return s.size() == n;
}

bool isEmpty()
{
    //add code here.
    return s.empty();
}

int pop()
{
    //add code here.
    int top = s.top();
    s.pop();
    min_s.pop();
    return top;
}

int getMin()
{
   //add code here.
    int top = min_s.top();
    return top;
}
