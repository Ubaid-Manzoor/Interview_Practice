#include <iostream>
#define N 1000000007

using namespace std;

long int exponentiation(long int base, long int exp){
    if(exp == 0)
        return 1;

    int tmp = exponentiation(base, exp/2);
    int result = (tmp * tmp) % N;

    if(exp % 2 != 0)
        result *= base;

    return result % N;
}

int main(){
    cout<<exponentiation(15, 7)<<endl;
}
