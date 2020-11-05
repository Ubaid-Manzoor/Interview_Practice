#include <iostream>

using namespace std;


double squareRoot(int number, int precision){
    int start=1;
    int end=number;
    int ans;

    while(start <= end){
        int mid = start + (end - start)/2;

        if(mid * mid == number)
            return mid;
        else if(mid * mid < number){
            start = mid + 1;
            ans = mid;
        }else
            end = mid - 1;
    }


    double ans_f = ans;
    double increment = 0.1;
    for(int i = 0 ; i < precision ; i++){
        while(ans_f * ans_f <= number)
            ans_f += increment;
        ans_f -= increment;
        increment /= 10;
    }

    return ans_f;
}

int main()
{
    // Function calling
    cout << squareRoot(50, 7) << endl;

    // Function calling
    cout << squareRoot(10, 4) << endl;

    return 0;
}
