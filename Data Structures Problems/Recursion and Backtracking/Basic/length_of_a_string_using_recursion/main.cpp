#include <iostream>

using namespace std;

int strLen(char str[], int index){
    if(str[index] == '\0')
        return index;
    return strLen(str, index+1);
}

int recLen(char str[]){
    return strLen(str, 0);
}

int main()
{
    char str[] = "GeeksforGeeks";
    cout << recLen(str)<<endl;
    return 0;
}
