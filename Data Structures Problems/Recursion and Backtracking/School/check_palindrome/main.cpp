// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution
{
    public:
        string is_palindrome(int n)
        {

            string number = to_string(n);
            if(number.size() == 1)
                return "Yes";
            if(number.size() == 2 and number[0] == number[1])
                return "Yes";
            if(number[0] != number[number.size()-1])
                return "No";

            return is_palindrome(stoi(number.substr(1,number.size()-2)));
        }
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        Solution ob;
        string ans = ob.is_palindrome(n);
        cout << ans <<"\n";
    }
    return 0;
}
  // } Driver Code Ends
