// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};



bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {

        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    cout<<isPalindrome(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
/*You are required to complete this method */

Node * reverse(Node *head){
    if(head->next == NULL) return head;
    Node newHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;

}

Node * mid_pointer(Node * head){
    Node *slow=head;
    Node *fast=head;
    Node *prev=NULL;
    while(fast != NULL and fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL;
    return slow;
}

bool isPalindrome(Node *head){
    if(head == NULL) return false;
    if(head->next == NULL) return true;

    Node *second_half = mid_pointer(head);
    Node *first_half = head;

    // REVERSE THE SECOND HALF NOT THE FIRST HALF
    second_half = reverse(second_half);

    while(second_half != NULL and first_half != NULL){
        if(second_half->data != first_half->data)
            return false;
        second_half = second_half->next;
        first_half = first_half->next;
    }
    return true;
}





