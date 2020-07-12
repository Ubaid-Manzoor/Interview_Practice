#include <iostream>

using namespace std;

bool check(string str1, string str2){
    if(str1.size() != str2.size()) return false;
    string temp = str1.append(str1);
    return temp.find(str2) != string::npos;
}

int main(){
    int tc;cin>>tc;
    for(int i=0; i < tc ;i++){
        string str1,str2;
        cin>>str1;cin>>str2;
        cout<<check(str1, str2)<<endl;
    }
}
