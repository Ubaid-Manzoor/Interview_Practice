// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string findMaximumNum(string str, int k);

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        cout<< findMaximumNum(str, k) << endl;
    }
    return 0;
}
// } Driver Code Ends


bool isGreater(string a, string b){
    if(a.length() != b.length()){
        if(a.length() < b.length())
            return false;
        else
            return true;
    }

    for(int i = 0 ; i < a.length() ; i++){
        if(a[i] > b[i]){
            return true;
        }else if(a[i] < b[i]){
            return false;
        }
    }
    return true;
}


void findMaximumNumHelper(string str, int s, int k, string &max){
    if(isGreater(str, max)){
        max = str;
    }
    if(k == 0){
        return;
    }

    for(int i = s ; i < str.length() ; i++){
        if(str[i] < str[s]){
            continue;
        }
        iter_swap(str.begin() + s, str.begin() + i);
        if(s == i){
            findMaximumNumHelper(str, s + 1, k, max);
        }else{
            findMaximumNumHelper(str, s + 1, k - 1, max);
        }
        iter_swap(str.begin() + s, str.begin() + i);
    }
}



string findMaximumNum(string str, int k){

    string max="0";
    findMaximumNumHelper(str, 0, k, max);
    return max;
}
