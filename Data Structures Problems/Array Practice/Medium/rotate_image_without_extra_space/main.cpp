#include <iostream>
#include <vector>

using namespace std;


// NOT DONE YET WILL DONE SOON ENOUGH

void printImage(const vector<vector<int>> &image){
    for(int i = 0 ; i < image[0].size() ; i++){
        for(int j = 0 ; j < image[0].size() ; j++){
            cout<<image[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void rotate_by_90(vector<vector<int>> &image){

    for(int i = 0 ; i < (image.size()/2) ; i++){

        int last_col = i + image.size() - 2 * i;
        int last_pixel = image[i][last_col];
        for(int row=i,col=last_col - 1; col > 0 ; col--){

        }
    }
}

int main(){
    int tc;cin>>tc;
    for(int i = 0 ; i < tc; i++){
        int size;cin>>size;
        vector<vector<int>> image(size,vector<int>(size));
        for(int j=0,row=0,col=0; j < size*size ;col++,j++){

            if(col == size){
                col %= size;
                row++;
            }
            int value;cin>>value;
            image[row][col] = value;
        }
        printImage(image);
    }
}
