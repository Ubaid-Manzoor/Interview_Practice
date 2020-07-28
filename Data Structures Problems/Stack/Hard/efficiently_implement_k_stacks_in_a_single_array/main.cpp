#include <iostream>
#include <vector>


using namespace std;

class kStacks{
private:
    int *arr;
    int *top;
    int *next;
    int free;
    int n,k;
public:
    kStacks(int k, int n);

    void push(int x,int sn);

    int pop(int sn);

    void display_top();

    void display_next();

    void display_arr();
};

kStacks::kStacks(int k, int n){
    this->n = n;this->k = k;
    arr = new int[n];
    top = new int[k];
    next = new int[n];

    for(int i = 0 ; i < k ; i++)
        top[i] = -1;

    for(int i = 0 ; i < n ; i++)
        next[i] = i+1;

    free = 0;
}

void kStacks::push(int x, int sn){
    if(free != n){
        arr[free] = x;

        int temp_free = free;
        free = next[free];

        next[temp_free] = top[sn-1];

        top[sn-1] = temp_free;

        free = next[free];
    }
}

int kStacks::pop(int sn){
//    int t = arr[next[top[sn]]];

//    top[sn] = next[]
}


void kStacks::display_next(){
    for(int i = 0 ; i < n ; i++)
        cout<<next[i]<<" ";
    cout<<endl;
}

void kStacks::display_top(){
    for(int i = 0 ; i < k ; i++)
        cout<<top[i]<<" ";
    cout<<endl;
}
void kStacks::display_arr(){
    for(int i = 0 ; i < n ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main()
{
    int k = 3, n = 10;
    kStacks ks(k, n);

    // Let us put some items in stack number 2
    ks.push(15, 2);
    ks.push(45, 2);
    ks.push(125, 2);
    ks.push(425, 2);

    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);

    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);

    ks.display_top();
    cout<<"========================"<<endl;
    ks.display_next();
    cout<<"========================"<<endl;
    ks.display_arr();
}
