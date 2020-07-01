#include <iostream>
#include <vector>

using namespace std;

bool pairExists(vector<int> arr, int sum){
    int i;
    for(i = 0; i < arr.size() ;i++){
        if(arr[i] > arr[(i + 1)%arr.size()])
            break;
    }
    int left = (i + 1)%arr.size();
    int right = i;

    for(;left != right;){
        if(arr[left] + arr[right] == sum){
            cout<<arr[left]<<" + "<<arr[right]<<" == "<<sum<<endl;
            return true;
        }
        if(sum > arr[left] + arr[right])
            left = (left + 1)%arr.size();
        else
            right = (right + arr.size() - 1)%arr.size();
    }

}

int main(){
    vector<int> arr = {11, 15, 6, 8, 9, 10};
    int sum = 23;
    if(!pairExists(arr, sum)){
        cout<<"Does not Exist"<<endl;
    }
//    cout<<(-1%5)<<endl;
}
