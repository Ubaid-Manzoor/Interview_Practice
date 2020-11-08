#include <iostream>
using namespace std;

void printCombinations(string input, int index=0, string output=""){
    int n = input.size();
    if(index == n){
        cout<<output<<endl;
        return;
    }

    output += input[index];
    output += " ";
    printCombinations(input, index + 1, output);

    if(index < n-1){
        output.pop_back();
        printCombinations(input, index + 1, output);
    }
}

int main(){
    string input = "1214";
    printCombinations(input);
}
