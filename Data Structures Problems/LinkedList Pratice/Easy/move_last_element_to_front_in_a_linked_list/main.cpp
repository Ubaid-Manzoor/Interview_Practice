// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
struct node* moveToFront(struct node *head);
int main()
{
    int t,n,x;
    cin>>t;
    while(t--){


        cin>>n;n=n-1;
        cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
            cin>>x;
          temp->next=new node(x);
          temp=temp->next;
            }

    struct node *newHead = moveToFront(head);

    printList(newHead);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);

 }
    }
    return 0;
}// } Driver Code Ends



//************************************* MY CODE STARTS HERE ************************************************

struct node * moveToFront(struct node *head){
    if(head->next == NULL) return head;

    node *current=head;
    node *prev=NULL;

    while(current->next != NULL){
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    current->next = head;
    head = current;

    return head;
}

























