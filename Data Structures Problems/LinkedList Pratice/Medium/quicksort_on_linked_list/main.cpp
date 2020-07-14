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
void quickSort(struct node **headRef);
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

    quickSort(&head);

    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);

 }
    }
    return 0;
}// } Driver Code Ends



/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */
//*******************************************************************************************************************
//*******************************************************************************************************************
//******************************************* MY CODE START HERE ****************************************************
//*******************************************************************************************************************
//*******************************************************************************************************************

// ASSUMING FIRST ELEMENT IS THE PIVOT
struct node* tail(struct node *head){
    node *current = head;
    while(current->next != NULL) current = current->next;
    return current;
}

void swap_value(struct node * first, struct node * second){
    int temp = first->data;
    first->data = second->data;
    second->data = temp;
}

struct node * partition(struct node *head, struct node *tail){
    node * i=head, *j=head->next;
    node *pivot = head;
    while(j != tail->next){
        if(j->data < pivot->data){
            swap_value(i->next,j);
            i = i->next;
        }
        j = j->next;
    }

    swap_value(pivot,i);
    return i;
}

void quickSortRec(struct node * head, struct node *tail){
    if(head == tail) return;
    if(tail == NULL or head == NULL) return;

    struct node * pivot = partition(head , tail);

    quickSortRec(head, pivot);
    quickSortRec(pivot->next, tail);
}

void quickSort(struct node **headRef) {
    quickSortRec(*headRef, tail(*headRef));
}



















