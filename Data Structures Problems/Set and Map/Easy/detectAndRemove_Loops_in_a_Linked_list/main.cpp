// C++ program to detect and remove loop in linked list
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to print linked list */
void printList(struct Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

bool detectAndRemoveLoop(struct Node* head){
    Node* current = head, *prev=NULL;
    unordered_set<Node*> hashmap;

    while(current != NULL){
        if(hashmap.count(current) == 1){
            prev->next = NULL;
            return true;
        }

        hashmap.emplace(current);
        prev = current;
        current = current->next;
    }

    return false;
}

struct Node* newNode(int key)
{
    struct Node* temp = new Node();
    temp->data = key;
    temp->next = NULL;
    return temp;
}

// Driver Code
int main()
{
    struct Node* head = newNode(50);
    head->next = newNode(20);
    head->next->next = newNode(15);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(10);

    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    bool loopExists = detectAndRemoveLoop(head);

    if(loopExists){
        cout << "Linked List after removing loop" << endl;

        printList(head);
    }else{
        cout<< "No Loop Exists "<<endl;
    }

    return 0;
}

// This code has been contributed by Striver
