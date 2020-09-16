// C++ Program to find the total
// number of distinct years
#include <bits/stdc++.h>
using namespace std;

// function to find the total
// number of distinct years

struct range{
    int start, end;
    range(int s,int e){
        start = s;
        end = e;
    }
};

void create_patter(vector<range*> &p){
    p[0] = p[1] = p[3] = p[4] = p[6] = p[7] = p[8] = p[9] = new range(48,57);
    p[2] = p[5] = new range(45,45);
}

int distinct_year(string str){
    vector<range*> pattern(10);
    create_patter(pattern);

    unordered_set<string> dates;
    string date="";
    for(int startIndex = 0 ; startIndex < str.size();){
        for(int i = 0 ;i < pattern.size() ; i++){
            int asscii = str[startIndex];
            if(pattern[i]->start <= asscii and asscii <= pattern[i]->end){
                date += str[startIndex];
                startIndex++;
            }else{
                if(asscii < 48 or asscii > 57)
                    startIndex++;
                date = "";
                break;
            }

            if(i == 9){
                dates.emplace(date.substr(date.size()-4, date.size()));
            }
        }
    }

    for(string d:dates)
        cout<<d<<endl;
    return dates.size();
}

// Driver code
int main()
{
    string str = "UN was established on 24-10-1945."
                 "India got freedom on 15-08-1947.";

//    string str = "Soon after the world war 2 ended on 02-09-1945.The UN was established on 24-10-1945.";

    cout << distinct_year(str)<<endl;

    return 0;
}
