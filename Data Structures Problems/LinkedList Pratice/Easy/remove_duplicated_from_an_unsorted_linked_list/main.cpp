// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Problem Link ::  https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

void print(Node *root)
{
Node *temp = root;
while(temp!=NULL)
{
cout<<temp->data<<" ";
temp=temp->next;
}
}

Node* removeDuplicates(Node *root);

int main() {
    // your code goes here
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0;i<K;i++){
        int data;
        cin>>data;
            if(head==NULL)
            head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp=temp->next;
            }
        }


        Node *result  = removeDuplicates(head);
        print(result);
        cout<<endl;

    }
    return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

// Function to remove duplicates from the linked list
// root: root of the linked list
Node * removeDuplicates( Node *head) {
 // your code goes here
    if(head == NULL or head->next == NULL) return head;
    Node *current = head->next;
    Node *prev=head;
    unordered_set<int> hash;
    hash.emplace(head->data);

    while(current != NULL){
        if(hash.find(current->data) == hash.end()){
            hash.emplace(current->data);
            prev = current;
            current = current->next;
        }else{
            prev->next = current->next;
            free(current);
            current = prev->next;
        }
    }

    return head;
}




