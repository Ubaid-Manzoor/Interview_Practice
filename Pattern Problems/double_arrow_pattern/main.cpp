#include <iostream>

using namespace std;

void double_arrow(int size=7){
    bool rool_back = false;
    for(int i = 1;;){
        if(rool_back and i == 0)
            break;
        for(int s = 0 ; s < (size-1) - 2*(i-1); s++)
            cout<<" ";
        for(int j = i ; j > 0 and i != 1 ; j-- )
            cout<<j;
        for(int s = 0 ; s < 1 + 2*(i-2) and i != 1; s++)
            cout<<" ";
        for(int j = 1 ; j <= i ; j++)
            cout<<j;

        if(i == size/2 + 1)
            rool_back = true;
        if(rool_back){
            i--;
        }else{
            i++;
        }

        cout<<endl;
    }
}

int main()
{
    double_arrow(17);
}
