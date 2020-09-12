// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N;
       cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }

        Node *res = mergeKLists(arr,N);
        printList(res);

   }

    return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */

struct compare{
    bool operator()(Node* node1, Node* node2){
        return node1->data >= node2->data;
    }
};

Node * mergeKLists(Node *arr[], int N){
    priority_queue<Node*, vector<Node*>, compare> minheap;

    for(int i = 0 ; i < N ; i++)
        minheap.push(arr[i]);

    Node *head=NULL;
    Node *tail=NULL;
    while(not minheap.empty()){
        Node* top = minheap.top();minheap.pop();
        if(not head){
            head = new Node(top->data);
            tail = head;
        }else{
            tail->next = new Node(top->data);
            tail = tail->next;
        }
        if(top->next)
            minheap.push(top->next);
    }

    return head;
}






















