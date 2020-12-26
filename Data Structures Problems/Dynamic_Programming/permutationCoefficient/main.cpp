#include <iostream>
#include <vector>

using namespace std;



int PermutationCoeff(int n, int k){
    vector<long long int> factArray;
    factArray.emplace_back(1);
    while(factArray.size() <= n){
        factArray.emplace_back(factArray.back() * factArray.size());
    }

    return factArray[n]/factArray[n-k];
}

int main()
{
    int n = 10, k = 2;

    cout << "Value of P(" << n << ", " << k
         << ") is " << PermutationCoeff(n, k);
    cout<<endl;
    return 0;
}
