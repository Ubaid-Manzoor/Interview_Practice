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


int getMiddleUtil(Node* head, Node* fastHead){
    if(fastHead == NULL)
        return head->data;
    if(fastHead->next == NULL)
        return head->data;

    return getMiddleUtil(head->next, fastHead->next->next);
}

int getMiddle(Node* head){

    return getMiddleUtil(head, head);
}
