#include <iostream>
#include <algorithm>
using namespace std;

void print_permutations(string str, int l=0){
    if(l == str.size()){
        cout<<str<<" ";
    }else{
        for(int i = l ; i < str.size() ; i++){
            sort(str.begin() + l, str.end());
            iter_swap(str.begin() + l, str.begin() + i);
            print_permutations(str, l+1);
            iter_swap(str.begin() + l, str.begin() + i);
        }
    }
}

int main() {
    //code
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        string str;cin>>str;

        print_permutations(str);
        cout<<endl;
    }
    return 0;
}
