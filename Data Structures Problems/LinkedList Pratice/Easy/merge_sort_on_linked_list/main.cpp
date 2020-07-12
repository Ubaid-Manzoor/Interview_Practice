// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends


/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

/* Function to mergesort the linked list
   It should return head of the modified list  */

Node * mergeLists(Node *left,Node *right){
    Node *result=NULL;

    if(left == NULL){
        return right;
    }else if(right == NULL){
        return left;
    }

    if(left->data < right->data){
        result = left;
        result->next = mergeLists(left->next,right);
    }else{
        result = right;
        result->next = mergeLists(left,right->next);
    }

    return result;
}

Node* mergeSort(Node* head) {
    if(head == NULL or head->next == NULL) return head;
    // your code here

    // First divide list in to two lists
    Node *slow=head;
    Node* fast=head;
    Node *left=head,*right;

    while(true){
        if(fast->next == NULL or fast->next->next == NULL){
            right = slow->next;
            slow->next = NULL;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }

    left = mergeSort(left);
    right = mergeSort(right);

    return mergeLists(left,right);
}


// { Driver Code Starts.


void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        a = mergeSort(a);
        printList(a);
    }
    return 0;
}  // } Driver Code Ends
