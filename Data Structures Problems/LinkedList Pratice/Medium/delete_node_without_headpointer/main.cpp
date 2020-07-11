// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}*head;

Node *findNode(Node* head, int search_for)
{
    Node* current = head;
    while (current != NULL)
    {
        if (current->data == search_for)
            break;
        current = current->next;
    }
    return current;
}


void insert()
{
    int n,i,value;
    Node *temp;
    scanf("%d",&n);

    for(i=0; i<n; i++)
    {
        scanf("%d",&value);
        if(i==0)
        {
            head=new Node(value);
            temp=head;
            continue;
        }
        else
        {
            temp->next= new Node(value);
            temp=temp->next;
            temp->next=NULL;
        }
    }
}

/* Function to print linked list */
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


void deleteNode(Node *node_ptr);

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */

    int t,k,n,value;

    scanf("%d",&t);
    while(t--)
    {
        insert();
        scanf("%d",&k);
        Node *del = findNode(head, k);
        if (del != NULL && del->next != NULL)
        {
            deleteNode(del);
        }
        printList(head);
    }
    return(0);
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
}*head;
*/

// This function should delete node from linked list. The function
// may assume that node exists in linked list and is not last node
// node: reference to the node which is to be deleted
void deleteNode(Node *node)
{
   // Your code here
   Node *prev = node;
   Node *current = node->next;
   while(true){
       int temp = prev->data;
       prev->data = current->data;
       current->data = temp;

       if(current->next == NULL){
            prev->next = NULL;
            free(current);
            return;
       }
       prev = prev->next;
       current = current->next;
   }
}
