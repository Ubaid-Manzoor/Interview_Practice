#include <iostream>

using namespace std;

void number_spiral(int size=4){
    bool rool_back = false;
    int spiral_size = 2 * size - 1;
    for(int rows = spiral_size,i=size ; rows > 0; rows--){
        bool increase_back = false;
        for(int to_print = size,j = 0; j < spiral_size;){
            if(to_print == i){
                for(int k = 0; k < spiral_size - 2 * (size-i); k++){
                    cout<<to_print;
                    j++;
                }
                increase_back = true;to_print++;
            }
            else{
                cout<<to_print;
                if(increase_back)
                   to_print++;
                else
                    to_print--;
                j++;
            }
        }

        if(rool_back ==false and i == 1)
            rool_back = true;
        if(rool_back)
            i++;
        else
            i--;
        cout<<endl;
    }
}

int main()
{
    number_spiral(9);
}
