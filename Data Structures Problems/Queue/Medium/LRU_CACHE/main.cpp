// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// design the class:

class Node{
public:
    int key;
    int data;
    Node *next;
    Node *prev;
    Node(int k,int d):key(k),data(d),next(NULL),prev(NULL){}
};



class LRUCache
{
private:
    unordered_map<int,Node*> cache;
    int capacity;

    Node *head,*tail; // WILL USE DOUBLY LINK LIST AS A QUEUE

public:
    int pop(){ // from queue
        Node *temp = head;

        int key = head->key;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL;
        free(temp);

        return key;
    }


    void push(int key, int value){
        Node *node = new Node(key,value);
        if(head == NULL){
            head=node;tail=node;
        }else{
            tail->next = node;
            node->prev = tail;
            tail=tail->next;
        }
        cache[key] = node;
    }

    void deleteNode(Node *node){
        if(node->prev != NULL)
            node->prev->next = node->next;
        if(node->next != NULL)
            node->next->prev = node->prev;

        if(node == head)
            head = node->next;
        if(node == tail)
            tail = tail->prev;
        free(node);
    }

    LRUCache(int cap):capacity(cap),head(NULL){}

    int get(int key)
    {
        // this function should return value corresponding to key
        if(cache.find(key) == cache.end())
            return -1;

        Node *node_to_delete = cache[key];
        int value = node_to_delete->data;
        deleteNode(node_to_delete);
        push(key, value);

        Node *node = cache[key];
        return node->data;
    }

    void set(int key, int value)
    {


        // storing key, value pair
        if(cache.find(key) == cache.end()){
            if(cache.size() < capacity)
                push(key,value);
            else{
                int key_to_delete = pop();
                cache.erase(key_to_delete);
                push(key,value);
            }
        }else{
            Node *node_to_delete = cache[key];
            deleteNode(node_to_delete);
            push(key,value);
        }
    }
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->set(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
