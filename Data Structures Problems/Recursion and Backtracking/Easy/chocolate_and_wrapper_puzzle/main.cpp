#include <iostream>

using namespace std;

int countMaxChocoUtil(int wraper_count, int wrap){
    if(wraper_count < wrap)
        return 0;
    int chocolate = wraper_count/wrap;
    int remain = wraper_count % wrap;

    return chocolate + countMaxChocoUtil(chocolate + remain, wrap);
}

int countMaxChoco(int money, int price, int wrap){
    int chocolate = money/price;

    return chocolate + countMaxChocoUtil(chocolate, wrap);
}

int main()
{
    int money = 20 ; // total money
    int price = 3; // cost of each candy
    int wrap = 5 ; // no of wrappers needs to be
    // exchanged for one chocolate.

    cout << countMaxChoco(money, price, wrap)<<endl;
    return 0;
}
