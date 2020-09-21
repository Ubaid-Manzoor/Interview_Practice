#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void count_unique(unordered_set<int> &s, int n){
    if(s.count(n) == 1)
        return;

    s.emplace(n);
    int new_n = n + 1;
    if(new_n % 10 == 0)
        new_n = new_n/10;

    count_unique(s, new_n);
}

int main()
{
    int n = 28;
    unordered_set<int> s;
    count_unique(s, n);

    cout << s.size() <<endl;

    return 0;
}
