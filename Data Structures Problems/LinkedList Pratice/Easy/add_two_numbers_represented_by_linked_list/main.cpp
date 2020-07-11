// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;

    Node* head = new Node(val);
    Node* tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

struct Node* addTwoLists(struct Node* first, struct Node* second);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;

        cin>>n;
        Node* first = buildList(n);

        cin>>m;
        Node* second = buildList(m);

        Node* res = addTwoLists(first,second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends


/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

Node * reverse(Node *head){
    Node *current = head, *prev;
    Node newHead=NULL;

    while(current != NULL){
        prev = current;
        current = current->next;
        prev->next = newHead;
        newHead = prev;
    }

    return newHead;
}

struct Node* addTwoLists(struct Node* first, struct Node* second){
    // code here
    first = reverse(first);
    second = reverse(second);
    Node *head=NULL;

    int carry = 0;
    while(first != NULL or second != NULL or carry != 0){
        int newVal = carry;
        if(first) newVal += first->data;
        if(second) newVal += second->data;

        Node *node = new Node(newVal % 10);
        node->next = head;
        head = node;

        carry = newVal/10;
        if(first) first = first->next;
        if(second) second = second->next;
    }


    return head;
}


