#include <iostream>
#include <vector>

using namespace std;

void printFactCombUtil(int curr, int candidate,int n, vector<int> result){
    if(curr == 1){
        for(int x: result)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
    for(int c = candidate ; c <= curr && c != n ; c++){
        if(curr % c == 0){
            result.emplace_back(c);
            printFactCombUtil(curr/c, c, n, result);
            result.pop_back();
        }
    }
}

void printFactComb(int n){

    vector<int> result;
    printFactCombUtil(n, 2, n, result);
}


int main()
{
    int n = 16;
    printFactComb(n);
    return 0;
}
