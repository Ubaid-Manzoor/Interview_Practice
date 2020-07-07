#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;



void printVec(const vector<int> &arr){
    for(int v:arr)
        cout<<v<<" ";
    cout<<endl;
}

int compare(int a, int b){
    return a > b;
}

void maximize_array(vector<int> array_one, vector<int> array_two){

    vector<int> big_array(2 * array_one.size());
    for(int i = 0 ; i < big_array.size() ; i++){
        if(i < array_two.size())
            big_array[i] = array_two[i];
        else
            big_array[i] = array_one[i - array_one.size()];
    }

    sort(big_array.begin(), big_array.end(),compare);

    unordered_set<int> hash;
    for(int i=0; hash.size() < array_one.size();i++){
            hash.emplace(big_array[i]);
    }



    for(int i = 0 ; i < array_two.size() ; i++)
        if(hash.find(array_two[i]) != hash.end()){
            cout<<array_two[i]<<" ";
            hash.erase(array_two[i]);
        }

    for(int i = 0 ; i < array_one.size() ; i++)
        if(hash.find(array_one[i]) != hash.end()){
            cout<<array_one[i]<<" ";
            hash.erase(array_one[i]);
        }

    cout<<endl;

}



int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int size;cin>>size;
        vector<int> one(size),two(size);
        for(int i = 0 ; i < size ; i++)
            cin>>one[i];
        for(int i = 0 ; i < size ; i++)
            cin>>two[i];

        maximize_array(one,two);
    }
}
