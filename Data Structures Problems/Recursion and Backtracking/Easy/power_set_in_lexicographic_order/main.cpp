#include <iostream>
#include <algorithm>

using namespace std;

void printPowerSet(string str,int start_index=0, string result=""){
    int n = str.size();
    if(n == 0)
        return;

    cout<<result<<endl;
    for(int i = start_index ; i < n ; i++){
        result += str[i];
        printPowerSet(str, i + 1, result);
        result.pop_back();
    }
}

void powerSet(string str){
    sort(str.begin(), str.end());
    printPowerSet(str);
}

int main()
{
    string str = "cabd";
    powerSet(str);
    return 0;
}
