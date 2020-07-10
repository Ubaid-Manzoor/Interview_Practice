// { Driver Code Starts
//Initial template for C++

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
        cout << node->data;
        node = node->next;
    }
    cout<<"\n";
}

Node* addOne(Node *head);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }

        head = addOne(head);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


//User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/


int recurse(Node *head){
    if(head->next == NULL){
        int result = head->data + 1;
        head->data = result%10;
        return result/10;
    }
    int carry = recurse(head->next);

    int result = head->data + carry;
    head->data = result%10;
    return result/10;
}

Node* addOne(Node *head) {
    // Your Code here

    int carry = recurse(head);
    if(carry == 1){
        Node *node = new Node(1);
        node->next = head;
        head = node;
    }

    return head;
}

