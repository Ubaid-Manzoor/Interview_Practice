// { Driver Code Starts
#include<iostream>
#include<stdio.h>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node* head1, struct Node* head2);

Node* inputList(int size)
{
    if(size==0) return NULL;

    int val;
    cin>> val;

    Node *head = new Node(val);
    Node *tail = head;

    for(int i=0; i<size-1; i++)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T,n1,n2,n3;

    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3;

        Node* head1 = inputList(n1);
        Node* head2 = inputList(n2);
        Node* common = inputList(n3);

        Node* temp = head1;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        temp = head2;
        while(temp!=NULL && temp->next != NULL)
            temp = temp->next;
        if(temp!=NULL) temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends


/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */


int size_of_list(Node * head){
    Node *current = head;
    int size=0;
    while(current != NULL){
        size++;
        current = current->next;
    }
    return size;
}



int intersectPoint(Node* head1, Node* head2){
    // Your Code Here
    Node *current1 = head1;
    Node *current2 = head2;

    int size1 = size_of_list(current1);
    int size2 = size_of_list(current2);
    int d = abs(size1 - size2);

    while(current1 != NULL and current2 != NULL){
        if(size1 > size2 and d != 0){
            current1 = current1->next;d--;
            continue;
        }else if(d != 0){
            current2 = current2->next;d--;
            continue;
        }

        if(current1 == current2){
            return current1->data;
        }


        current1 = current1->next;
        current2 = current2->next;
    }

    return -1;
}
