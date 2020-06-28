#include <iostream>

using namespace std;

void Z_pattern(int rows=3){
    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){
            if(i == 0 || i == rows-1)
                cout<<"*";
            else if(j == rows - (i + 1)){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    for(int i = 3 ; i < 10; i++){
        Z_pattern(i);
        cout<<"------------------------------"<<endl;
    }

}
