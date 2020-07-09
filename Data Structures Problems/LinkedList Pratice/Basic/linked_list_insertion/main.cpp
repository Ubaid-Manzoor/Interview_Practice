// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Problem Link :: https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/1

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

Node *insertAtBegining(Node *head, int newData);
Node *insertAtEnd(Node *head, int newData);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        struct Node *head = NULL;
        for (int i = 0; i < n; ++i)
        {
            int data, indicator;
            cin>>data;
            cin>>indicator;
            if(indicator)
                head = insertAtEnd(head, data);
            else
                head = insertAtBegining(head, data);
        }
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// MY CODE STARTS HERE

// function inserts the data in front of the list
Node *insertAtBegining(Node *head, int data) {
   Node *startnode = new Node(data);
   startnode->next = head;
   head = startnode;

   return head;
}


// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int data)  {
   // Your code here
    if(head == NULL){
        Node *node = new Node(data);
        head = node;
        return head;
    }

    Node *current = head;
    while(current->next != NULL){
        current = current->next;
    }

    Node *node = new Node(data);
    current->next = node;

    return head;
}
