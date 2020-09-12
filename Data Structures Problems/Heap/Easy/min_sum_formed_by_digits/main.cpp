#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int min_sum(vector<int> digits){
    make_heap(digits.begin(),digits.end());

    int num1=0;
    int num2=0;


    int exp=0;
    int max_digit;
    while(not digits.empty()){
        max_digit = digits.front();
        pop_heap(digits.begin(),digits.end());digits.pop_back();
        num1 += max_digit * (pow(10,exp));

        if(digits.empty())
            break;

        max_digit = digits.front();
        pop_heap(digits.begin(),digits.end());digits.pop_back();
        num2 += max_digit * (pow(10, exp));

        exp++;
    }

    return num1 + num2;
}

int main()
{
    int tc;cin>>tc;

    for(int i = 0 ; i < tc ; i++){
        int n;cin>>n;

        vector<int> arr(n);
        for(int j = 0 ; j < n ; j++){
            cin>>arr[j];
        }

        cout<<min_sum(arr)<<endl;
    }
}



















