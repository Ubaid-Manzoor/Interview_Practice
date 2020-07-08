// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/insert-in-middle-of-linked-list/1

struct Node
{
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;

        struct Node *head = new Node(x);
        struct Node *tail = head;

        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }

        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
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

// MY CODE

// function should insert node at the middle
// of the linked list
Node* insertInMiddle(Node* head, int x){
    int size=1;
    Node *current = head;

    while(current->next != NULL){
        current = current->next;
        size++;
    }

    int mid = (size+1) / 2;
    if(head == NULL){
        Node *node = new Node(x);
        head = node;
        return head;
    }

    current = head;
    int position=1;
    while(current->next != NULL and position != mid){
        current = current->next;
        position++;
    }

    Node *node = new Node(x);
    node->next = current->next;
    current->next = node;
    return head;
}


Node* insertInMiddle_better(Node* head, int x){
    if(head == NULL)
        return new Node(x);

    Node *node = new Node(x);
    Node *slow=head;
    Node *fast=head;

    while(fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    node->next = slow->next;
    slow->next = node;
    return head;
}






