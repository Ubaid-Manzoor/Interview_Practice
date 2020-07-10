// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

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
        Node *head = NULL;
        Node *temp = head;

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
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

// root: head node
Node *removeDuplicates(Node *root){
    if(root == NULL or root->next == NULL) return root;
    Node *current = root->next;
    Node *prev = root;

    while(current != NULL){
        if(prev->data == current->data){
            prev->next = current->next;
            free(current);
            current = prev->next;
        }
        else{
            prev = current;
            current = current->next;
        }
    }

    return root;
}
