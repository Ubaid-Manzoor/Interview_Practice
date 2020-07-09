// { Driver Code Starts
//Code by Shubham Joshi
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string data;
    Node* next;

    Node(string x){
        data = x;
        next = NULL;
    }
};

Node *newNode(string str)
{
    Node *new_node = new Node(str);
    new_node->next = NULL;
    return new_node;
}

bool compute(struct Node* root);

void print(Node *root)
{
    Node *temp = root;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
}

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
        string str="";
        cin>>str;
            if(head==NULL)
            head=temp=new Node(str);
            else
            {
                temp->next = new Node(str);
                temp=temp->next;
            }
        }
        if(compute(head))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}// } Driver Code Ends


/*
The structure of linked list is the following
struct Node
{
    string data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

bool ispalindrome(string str){
    int start,end;
    for(start=0,end=str.size()-1; start <= end ; start++,end--){
        if(str[start] != str[end])
            return false;
    }
    return true;
}

bool compute(Node* root){
    string str="";

    Node* current=root;
    while(current != NULL){
        str += current->data;
        current = current->next;
    }

    return ispalindrome(str);
}



