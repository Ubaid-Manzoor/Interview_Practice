#include <iostream>
#include <cmath>

using namespace std;

int countWaysUtil(int x, int n,int num){
    int new_x = x - pow(num, n);
    if(new_x == 0)
        return 1;
    if(new_x < 0)
        return 0;

    return  countWaysUtil(new_x, n, num + 1) + countWaysUtil(x, n, num + 1);
}

int countWays(int x, int n){
    return countWaysUtil(x, n, 1);
}

int main()
{
    int x = 100, n = 2;
    cout << countWays(x, n)<<endl;
    return 0;
}
