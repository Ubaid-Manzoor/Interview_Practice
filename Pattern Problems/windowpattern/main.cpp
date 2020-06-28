#include <iostream>

using namespace std;

void window(int size=6){
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            if(i == 0 || i == size - 1)
                cout<<" *";
            else if(j == 0 || j == size - 1)
                cout<<" *";
            else if(size % 2 == 0){
                if(j == size/2 || j == size/2 - 1)
                    cout<<" *";
                else if(i == size/2 || i == size/2 - 1)
                    cout<<" *";
                else
                    cout<<"  ";
            }else{
                if(j == size/2)
                    cout<<" *";
                else if(i == size/2)
                    cout<<" *";
                else
                    cout<<"  ";
            }
        }
        cout<<endl;
    }
}

int main()
{
    window(7);
}
