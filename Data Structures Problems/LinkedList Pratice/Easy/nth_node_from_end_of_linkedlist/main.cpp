// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/nth-node-from-end-of-linked-list/1

/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node* head, int n);



/* Driver program to test above function*/
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}// } Driver Code Ends


/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/

int recurse(Node *current, int size, int &n){
    if(current == NULL)
        return -1;

    size++;
    int value = recurse(current->next, size ,n);
    n--;

    if(n == 0)
        return current->data;
    else
        return value;
}


int getNthFromLast_with_recursion(Node *head, int n){
       int size=0;
       return recurse(head,size,n);
}


int getNthFromLast(Node *head, int n){
    Node *first=head;
    Node *second=head;

    int position = 1;
    while(second->next != NULL){
        second = second->next;
        if(position >= n)
            first = first->next;
        position++;
    }

    if(n > position)
        return -1;
    return first->data;
}
