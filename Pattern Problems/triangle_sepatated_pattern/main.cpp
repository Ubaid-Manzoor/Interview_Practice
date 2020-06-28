#include <iostream>

using namespace std;

void triangle_separator(int n=100){
    for(int i = 0; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i == n - j - 1)
                cout<<'/';
            else if(i == j)
                cout<<"\\";
            else
                cout<<"*";
        }
        cout<<endl;
    }
}

int main()
{
    triangle_separator();
}
