#include <iostream>

using namespace std;

int product(int x, int y){
    if(x < y)
        swap(x, y);
    else if(y != 0)
        return x + product(x, y-1);
    else
        return 0;
}

// Driver Code
int main()
{
    int x = 5, y = 2;
    swap(x, y);
//    cout<<x<<" "<<y<<endl;
    cout << product(x, y);
    return 0;
}
