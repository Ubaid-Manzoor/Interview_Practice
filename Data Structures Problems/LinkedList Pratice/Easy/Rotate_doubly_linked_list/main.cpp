// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
struct node* update(struct node*start,int p);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,p;
        cin>>n>>p;
        struct node*start = NULL;
        struct node* cur = NULL;
        struct node* ptr = NULL;

        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ptr=new node(a);
            ptr->data=a;
            ptr->next=NULL;
            ptr->prev=NULL;
            if(start==NULL)
            {
                start=ptr;
                cur=ptr;
            }
            else
            {
                cur->next=ptr;
                ptr->prev=cur;
                cur=ptr;
            }
        }
        struct node*str=update(start,p);
        while(str!=NULL)
        {
            cout<<str->data<<" ";
            str=str->next;
        }
        cout<<endl;
    }
}

 // } Driver Code Ends


//User function Template for C++

/*
struct node
{
  int data;
  struct node*next,*prev;

  node(int x){
      data = x;
      next = NULL;
      prev = NULL;
  }

};
*/

struct node*update(struct node*head,int p){
    if(head == NULL or head->next == NULL) return head;
    //Add your code here

    node *current=head,*newHead,*prev=NULL;
    node *start = head;

    int position=0;
    while(current != NULL){
        if(position == p){
            newHead = prev->next;
            prev->next = NULL;
        }

        prev = current;
        current = current->next;
        position++;
    }

    if(position == p) // position gives size of linked list , now if p == size that we dont have to rotate at all
        return head;

    if(current != NULL){
        current->next = star;
        start->prev = current;
    }else{
        prev->next = start;
        start->prev = prev;
    }

    return newHead;
}







