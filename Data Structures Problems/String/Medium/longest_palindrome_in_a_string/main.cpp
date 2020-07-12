#include <iostream>

using namespace std;

pair<int,int> length_of_longest_palindrome(string str){
    int palindrome_length=1;
    int start_index = 0;
    // CHECK FOR ODD PALINDROMES
    for(int k = 0 ; k < str.size() ; k++){
        for(int i=k,j=k; i > -1 and j < str.size() ;){
            if(palindrome_length < j - i + 1 and str[i] == str[j]){
                palindrome_length = j - i + 1;
                start_index=i;
            }
            else if(str[i] != str[j])
                break;
            i--;j++;
        }
    }


    // CHECK FOR EVEN PALINDROMES
    for(int k = 0 ; k < str.size() ; k++){
        for(int i=k,j=k+1; i > -1 and j < str.size() ;){
            if(palindrome_length < j - i + 1 and str[i] == str[j]){
                palindrome_length = j - i + 1;
                start_index=i;
            }
            else if(str[i] != str[j])
                break;
            i--;j++;
        }
    }

    return make_pair(start_index, palindrome_length);
}


int main(){
    int tc;cin>>tc;
    for(int i=0; i < tc ; i++){
        string str;cin>>str;
        pair<int,int> result = length_of_longest_palindrome(str);
        for(int i = result.first; i < result.first + result.second ; i++)
            cout<<str[i];
        cout<<endl;
    }
}
