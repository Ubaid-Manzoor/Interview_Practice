#include <iostream>
#include <vector>

using namespace std;

static int called=0;
void printCombinationUtil(int arr[], int n, int r, vector<int> &result, int index=0){
    called++;
    if(result.size() == r){
        for(int x:result)
            cout<<x<<" ";
        cout<<endl;
        return;
    }

    for(int i = index ; i < n ; i++){
        result.emplace_back(arr[i]);
        printCombinationUtil(arr, n, r, result, i + 1);
        result.pop_back();
    }
}

void printCombination(int arr[], int n, int r){
    vector<int> result;
    printCombinationUtil(arr, n, r, result);
    cout<<"called : "<<called<<" times"<<endl;
}

void combinationUtil(int arr[], int n, int r, int index, vector<int> &result){
    if(result.size() == r){
        for(int x:result)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
    called++;
    if(index < n){
        result.emplace_back(arr[index]);
        combinationUtil(arr, n, r, index+1, result);

        result.pop_back();
        combinationUtil(arr, n, r, index+1, result);
    }
}

void printCombination_(int arr[], int n, int r){
    vector<int> result;
    combinationUtil(arr, n, r, 0, result);
    cout<<"called : "<<called<<" times"<<endl;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printCombination(arr, n, r);
}
