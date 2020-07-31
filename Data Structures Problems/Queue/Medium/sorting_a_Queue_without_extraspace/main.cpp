#include <iostream>
#include <queue>
#include <limits>

using namespace std;

int getMin(queue<int> &q, int first_n){
    int n = q.size();

    int min_value = q.front();q.pop();
    for(int i = 0 ; i < n-1 ; i++){
        if(i < first_n-1){
            if(q.front() < min_value){
                q.emplace(min_value);
                min_value = q.front();
                q.pop();
            }else{
                q.emplace(q.front());q.pop();
            }
        }else{
            q.emplace(q.front());q.pop();
        }
    }

    return min_value;
}


void sortQueue(queue<int> &q){

    int n = q.size();
    for(int i = 0 ; i < n ; i++){
        int min = getMin(q, n - i);
        q.emplace(min);
    }
}

using namespace std;

int main(){
    queue<int> q;


    q.push(30);
    q.push(11);
    q.push(15);
    q.push(4);
    q.push(303);
    q.push(1);
    q.push(5);
    q.push(41);
    q.push(3);
    q.push(131);
    q.push(100);
    q.push(0);

    // Sort queue
    sortQueue(q);

    // Print sorted queue
      while (q.empty() == false)
      {
         cout << q.front() << " ";
         q.pop();
      }
      cout << endl;
}
