// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {

    int t;
    cin>>t;
    while(t--)
    {
    string s;
    cin >> s;

    cout << reverseWord(s) << endl;
    }
    return 0;

}

// } Driver Code Ends


//User function Template for C++

void swapChars(string &str, int index){
    if(index < str.size() - index - 1){
        swap(str[index], str[str.size() - index - 1]);
        swapChars(str, index+1);
    }
}

string reverseWord(string str){
  swapChars(str, 0);
  return str;
}
