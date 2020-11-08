#include <iostream>

using namespace std;

bool isConsonant(char c){
    c = tolower(c);
    if(not (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') and c > 96 and c <123 )
        return true;
    return false;
}

int totalConsonants(string str,int length){
    if(length == 0){
        return 0;
    }else{
        return isConsonant(str[length-1]) + totalConsonants(str, length-1);
    }
}

int main()
{
//    string str = "abc de";
    string str = "geeksforgeeks portal";
    cout << totalConsonants(str, str.length())<<endl;
    return 0;
}
