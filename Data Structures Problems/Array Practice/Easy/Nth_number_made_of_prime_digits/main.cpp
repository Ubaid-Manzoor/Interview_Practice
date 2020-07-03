#include <iostream>
#include <string>

using namespace std;

bool isDigitPrime(int number){
    string num = to_string(number);
    for(int s_i = 0 ; s_i < num.size() ; s_i++){
        if(num[s_i] != '2' && num[s_i] != '3' && num[s_i] != '5' && num[s_i] != '7'){
            return false;
        }
    }
    return true;
}

int main()
{
    int testcase;
    cin>>testcase;

    for(int tc = 0 ; tc < testcase ; tc++ ){
        int prime_count = 0;
        int N;
        cin>>N;
        for(int i = 2 ;  ; i++){
            if(isDigitPrime(i)){
                prime_count++;
            }
            if(prime_count == N){
                cout<<i<<endl;
                break;
            }
        }
    }
}
