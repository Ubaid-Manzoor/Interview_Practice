#include <iostream>
#include <list>

using namespace std;

class HashMap {
private:
    int BUCKET;
    list<int> *table;

public:

    HashMap(int size);
    int hashFunction(int key);
    void insert(int x);
    void deleteX(int x);
    void displayHash();

};

HashMap::HashMap(int size){
    this->BUCKET = size;
    table = new list<int>[this->BUCKET];
}

int HashMap::hashFunction(int key){
    return key % this->BUCKET;
}

void HashMap::insert(int x){
    int index = hashFunction(x);

    for(int v:table[index])
        if(v == x)
            return;

    table[index].emplace_back(x);
}

void HashMap::deleteX(int x){
    int index = hashFunction(x);

    table[index].remove(x);
}

void HashMap::displayHash(){
    for(int i = 0 ;i < this->BUCKET ; i++){
        cout<<i<<" ";
        for(int x: table[i])
            cout<<x<<"-->";
        cout<<endl;
    }
}

// Driver program
int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12, 11,14};
  int n = sizeof(a)/sizeof(a[0]);

  // insert the keys into the hash table
  HashMap h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insert(a[i]);

  // delete 12 from hash table
  h.deleteX(8);

  // display the Hash table
  h.displayHash();

  return 0;
}
