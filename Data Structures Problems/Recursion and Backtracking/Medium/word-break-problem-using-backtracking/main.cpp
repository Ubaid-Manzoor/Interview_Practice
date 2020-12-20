#include <iostream>
#include <vector>

using namespace std;

int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}

void wordBreakUtil(string input, int index, vector<string> &sentence, string word=""){
    if(index >= input.size()){
        for(string w: sentence){
            cout<<w<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i = index ; i < input.size() ; i++){
        if(dictionaryContains(word + input[i])){
            word += input[i];
            sentence.emplace_back(word);
            wordBreakUtil(input, i + 1, sentence);
            sentence.pop_back();
        }else
            word += input[i];
    }
}

void wordBreak(string input){
    vector<string> sentence;
    wordBreakUtil(input, 0, sentence);
}

int main()
{
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");

    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}
