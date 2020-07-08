// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data <<" ";
        node = node->next;
    }
    cout<<"\n";
}
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout<<getMiddle(head)<<endl;
    }
    return 0;
}

// } Driver Code Ends

/* Link list Node
struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head){

    if(head == NULL) return -1;

    int size=1;
    Node *current = head;

    while(current->next != NULL){
        current = current->next;
        size++;
    }

    int mid = size/2 + 1;

    current = head;
    int position = 1;
    while(position != mid){
        current = current->next;
        position++;
    }

    return current->data;
}




