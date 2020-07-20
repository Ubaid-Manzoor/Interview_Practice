// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>

using namespace std;

// structure of node of doubly linked list
struct Node {
    int data;
    struct Node* next, *prev;
};

// function to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'

int getPair(Node * start, Node *end,int x){

    int count=0;
    while(start != end and end != start->prev){
        int current_sum = start->data + end->data ;
        if(current_sum == x){
            cout<<"("<<start->data<<","<<end->data<<"),";
            count++;
            start = start->next;
            end = end->prev;
        }else if(current_sum < x)
            start = start->next;
        else
            end = end->prev;
    }

    return count;
}


int countTriplets(struct Node* head, int x) {
    Node *current=head;
    int triplet_count=0;

    Node *last;
    // GET THE POINTER OF LAST NODE
    while(current->next != NULL)
        current = current->next;
    last = current;

    Node *first = head;
    while(first->next->next != NULL){
        int pair_count = getPair(first->next, last, x - first->data);

        // *** FOR PRINTING PAIRS ***
        if(pair_count != 0){
            cout<<" with "<<first->data<<" |"<<endl;
        }

        triplet_count += pair_count;
        first = first->next;
    }

    return triplet_count;
}

// A utility function to insert a new node at the
// beginning of doubly linked list
void insert(struct Node** head, int data)
{
    // allocate node
    struct Node* temp = new Node();

    // put in the data
    temp->data = data;
    temp->next = temp->prev = NULL;

    if ((*head) == NULL)
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

// Driver program to test above
int main()
{
    // start with an empty doubly linked list
    struct Node* head = NULL;

    // insert values in sorted order
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int x = 11;

    int count = countTriplets(head, x);
    cout<<" COUNT :: "<<count<<endl;
    return 0;
}
