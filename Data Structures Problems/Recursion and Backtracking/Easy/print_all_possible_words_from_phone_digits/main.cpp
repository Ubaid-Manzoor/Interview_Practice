#include <iostream>

using namespace std;

const string phoneDigits[10]
    = { "",    "",    "abc",  "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz" };

// 2  3  4

void printWordsHelper(int numbers[], int n, int numberIndex=0, string result=""){

    if(n <= 0){
        cout<<result<<" ";
        return;
    }

    string words = phoneDigits[numbers[numberIndex]];
    if(words.length() == 0)
        printWordsHelper(numbers, n - 1, numberIndex + 1, result);

    for(int i = 0 ; i < words.length() ; i++)
        printWordsHelper(numbers, n - 1, numberIndex + 1, result + words[i]);
}
void printWords(int numbers[],int n){
    printWordsHelper(numbers, n);
    cout<<endl;
}

int main(void)
{
    int number[] = { 2,3, 4 };
    int n = sizeof(number) / sizeof(number[0]);
    printWords(number, n);
    return 0;
}
