// C++ program to find a pair with given sum x.
#include<bits/stdc++.h>
using namespace std;

// structure of node of doubly linked list
struct Node
{
    int data;
    struct Node *next, *prev;
};

// Function to find pair whose sum equal to given value x.

struct Node * gettail(struct Node *head){
    Node *current=head;
    while(current->next != NULL)
        current = current->next;
    return current;
}
void pairSum(struct Node *head, int x) {
    struct Node * tail = gettail(head);
    struct Node * start=head;

    while(start != tail and tail != start->prev){
        if( (start->data + tail->data) == x){
            cout<<"("<<start->data<<","<<tail->data<<")"<<endl;
            start = start->next;
            tail = tail->prev;
        }else if(start->data + tail->data < x)
            start = start->next;
        else
            tail = tail->prev;
    }
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = temp->prev = NULL;
    if (!(*head))
        (*head) = temp;
    else
    {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program
int main()
{
    struct Node *head = NULL;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);
    int x = 7;

    pairSum(head, x);

    return 0;
}
