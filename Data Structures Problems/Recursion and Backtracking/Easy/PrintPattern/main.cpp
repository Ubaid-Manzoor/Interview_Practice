#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int printBefore(int n){
    if(n <= 0)
        return n;
    cout<<n<<" ";
    printBefore(n-5);
}

void printAfter(int n, int middle){
    if(middle == n){
        cout<<middle<<" "<<endl;
        return;
    }
    cout<<middle<<" ";
    printAfter(n, middle + 5);
}
void printPattern(int n){
    int middle=printBefore(n);
    printAfter(n, middle);

}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        printPattern(n);

    }
}
