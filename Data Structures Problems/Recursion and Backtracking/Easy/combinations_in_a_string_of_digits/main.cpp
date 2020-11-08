#include <iostream>
using namespace std;

void printCombinations(int s, string input, string output, int sizeToTake){
    if(n > 0){
        output += input.substr(s, sizeToTake);
        printCombinations(n+1, , input, output, sizeToTake);
        sizeToTake++;
    }else
        cout<<output<<endl;
}

int main(){
    string input = "123";

    printCombinations(0, input, "", 1);
}
