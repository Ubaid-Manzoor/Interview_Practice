#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void missing_and_repeated(vector<int> &arr){

    int repeated = -1;
    for(int i = 0 ; i < arr.size(); i++){
        if(arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -1 * arr[abs(arr[i]) - 1];
        else
            if(repeated == - 1)
                repeated = abs(arr[i]);
    }

    int missing;
    for(int i = 0 ; i < arr.size(); i++){
        if(arr[i] > 0)
            missing = i + 1;
    }

    cout<<repeated<<" "<<missing<<endl;
}

int main()
{
    int tc;cin>>tc;
    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;
        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            int value;cin>>value;
            arr[j] = value;
        }
        missing_and_repeated(arr);
    }
}
