// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

// PROBLEM LINK :: https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;

    cin>>val;
    head = tail = new Node(val);

    while(--size)
    {
        cin>>val;
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
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>> n >> m;

        Node* head1 = inputList(n);
        Node* head2 = inputList(m);

        Node* result = findIntersection(head1, head2);

        printList(result);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2){
    Node *current1 = head1;
    Node *current2 = head2;

    Node *head=NULL,*current;
    while(current1 != NULL and current2 != NULL){
        if(current1->data == current2->data){
            Node *node = new Node(current1->data);
            if(!head) {
                head = node;
                current = head;
            }else{
                current->next = node;
                current = current->next;
            }
            current1 = current1->next;
            current2 = current2->next;
        }else if(current1->data < current2->data)
            current1 = current1->next;
        else
            current2 = current2->next;
    }

    return head;
}














