#include <iostream>

using namespace std;

void drawPattern(int row, int col){
    if(col == 0){
        cout<<endl;
        row--;
        col = row;
        if(row == 0)
            return;
    }

    cout<<"*";
    drawPattern(row, --col);
}

int main(){
    int size = 20;
    drawPattern(size,size);
}