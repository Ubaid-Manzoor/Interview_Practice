// { Driver Code Starts
#include<bits/stdc++.h>
#include <iostream>

using namespace std;
/* structure for a Node */
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};

struct Node* exchangeEndNodes(struct Node *head);

/* function to insert a new_Node in a list in sorted way.
   Note that this function expects a pointer to head Node
   as this can modify the head of the input linked list */

/* Function to print Nodes in a given linked list */
void printList(struct Node *start)
{
  struct Node *temp;

  if(start != NULL)
  {
    temp = start;
    do { printf("%d ", temp->data);
      temp = temp->next;
    } while(temp != start);
    printf("\n");
  }
}
/* Driver program to test above functions */
int main()
{
int t,n,x;
scanf("%d",&t);
int arr;
  while(t--){
  scanf("%d",&n);
  int list_size, i;

  /* start with empty linked list */
  struct Node *start = NULL;
  struct Node *temp,*r;


    /* Create linked list from the array arr[].
    Created linked list will be 1->2->11->56->12 */
    if(n>0){
      scanf("%d",&arr);

    temp = new Node(arr);
    start=temp;
    r=start;
    }
    for (i = 0; i<n-1; i++)
    {
        scanf("%d",&arr);
        temp = new Node(arr);
        r->next=temp;
        r=r->next;
    }

    if(n>0)
    temp->next=start;

//    scanf("%d",&x);
//    start = sortedInsert(start,x);
    Node* newStart = exchangeEndNodes(start);
    printList(newStart);
    r=start;
    while(r!=start->next)
    {

      temp=start;
      start=start->next;
      free(temp);
    }
    free(start);
}
  return 0;
}
// } Driver Code End 0;

struct Node* exchangeEndNodes(struct Node *head){
//    printList(head);
    if(head->next == head) return head;
    if(head->next->next == head)return head->next;

    Node *current=head,*prev=NULL;

    while(current->next != head){
        prev = current;
        current = current->next;
    }

    current->next = current->next->next;
    prev->next = head;
    head = current;
    prev->next->next = head;
    return head;
}

















