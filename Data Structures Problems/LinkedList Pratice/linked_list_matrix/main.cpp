// { Driver Code Starts
#include <bits/stdc++.h>
#define MAX 20

// Problem Link :: https://practice.geeksforgeeks.org/problems/linked-list-matrix/1

using namespace std;

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};

void display(Node* head)
{
    Node* Rp;
    Node* Dp = head;
    while (Dp) {
        Rp = Dp;
        while (Rp) {
            cout << Rp->data << " ";
            Rp = Rp->right;
        }

        Dp = Dp->down;
    }
}

Node* constructLinkedMatrix(int mat[MAX][MAX], int n);

// driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int mat[MAX][MAX];
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                cin>>mat[i][j];
        Node* head = constructLinkedMatrix(mat, n);
        if(!head)cout<<"-1";
        else display(head);
        cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends


/*structure of the node of the linked list is as

struct Node
{
    int data;
    Node* right, *down;

    Node(int x){
        data = x;
        right = NULL;
        down = NULL;
    }
};
*/
// n is the size of the matrix
// function must return the pointer to the first element
// of the in linked list i.e. that should be the element at arr[0][0]
Node* constructLinkedMatrix(int mat[MAX][MAX], int n){
    Node *head=NULL,*rowHead;
    Node *prevCurrent=NULL;
    int row=0;

    Node *node = new Node(mat[0][0]);
    head = node;
    rowHead = node;
    while(row < n){
        Node *current = rowHead;
        int col=1;
        while(col < n){
            Node *node = new Node(mat[row][col]);
            if(prevCurrent != NULL){
                prevCurrent->down = node;
                prevCurrent = prevCurrent->right;
            }

            current->right = node;
            current = current->right;
            col++;
        }
        prevCurrent = rowHead->right;
        row++;
        if (row == n) break;
        rowHead->down = new Node(mat[row][0]);
        rowHead = rowHead->down;

    }
    return head;
}













