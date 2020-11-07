#include <iostream>

using namespace std;

void generateBinaryUtil(int k, string b){
    if(k > 0){
        generateBinaryUtil(k-1, b + "0");
        if(b[b.size() - 1] != '1')
            generateBinaryUtil(k-1, b + "1");
    }else
        cout<<b<<" ";
}

void generateBinary(int K){
    generateBinaryUtil(K, "");
}

int main()
{
    int K = 3;
    generateBinary(4);
}
