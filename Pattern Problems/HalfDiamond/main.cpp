#include <iostream>

using namespace std;

void half_diamond(int size){
    bool rool_back = false;
    for(int i = 1; i != 0;){
        for(int j = 1 ; j <= i; j++){
            cout<<"*";
        }

        if(i == size)
            rool_back = true;

        if(rool_back)
            i--;
        else
            i++;
        cout<<endl;
    }
}

int main()
{
    half_diamond(10);
}
