// C++ implementation to reverse a doubly linked list
// in groups of given size
#include <bits/stdc++.h>

using namespace std;

// a node of the doubly linked list
struct Node {
    int data;
    Node *next, *prev;
};

// function to get a new node
Node* getNode(int data)
{
    // allocate space
    Node* new_node = (Node*)malloc(sizeof(Node));

    // put in the data
    new_node->data = data;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}


// Function to print nodes in a
// given doubly linked list
void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfK(Node* head, int k) {
    Node *current=head->next;
    Node *newHead=head;
    Node *prev=head;
    int count=1;

    while(current != NULL and count < k){
        Node *temp = current->next;

        // PLUCK CURRENT OUT THE LIST
        prev->next = current->next;
        if(prev == head)            // prev never change, it always points to first element in k size
            prev->prev = current;
        if(current->next != NULL)   // at the end of the list when current->next is NULL current->next->prev does not exist
            current->next->prev = prev;

        // LINK THE CURRENT TO THE FRONT
        current->next = newHead;
        current->prev = NULL;
        newHead = current;

        current = temp;
        count++;
    }


    if(current != NULL){
        prev->next = revListInGroupOfK(current, k);
        prev->next->prev = prev;
    }

    return newHead;
}



// Driver program to test above
int main()
{
    // Start with the empty list
    Node* head = NULL;

    // Create doubly linked: 10<->8<->4<->2
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
    push(&head, getNode(22));
    push(&head, getNode(43));
    push(&head, getNode(84));
    push(&head, getNode(150));
    push(&head, getNode(843));
    push(&head, getNode(1504));
    push(&head, getNode(15042));

    int k = 4;

    cout << "Original list: ";
    printList(head);

    // Reverse doubly linked list in groups of
    // size 'k'
    head = revListInGroupOfK(head, k);

    cout << "\nModified list: ";
    printList(head);

    return 0;
}
