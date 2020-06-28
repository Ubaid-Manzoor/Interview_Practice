#include <iostream>

using namespace std;

void X_patter(int n=3){
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == j or i == n - j - 1)
                cout<<"$";
            else
                cout<<" ";
        }
        cout<<endl;
    }
}

int main(){
    X_patter(10);
}
