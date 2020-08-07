// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}// } Driver Code Ends


//User function Template for C++
/*
structure of the node of the binary tree is as
struct Node {
    int data;
    Node* left, *right;
};
*/
// your task is to complete this function
struct node {
    int height;
    int sum;
    node(int h, int s){
        height = h;
        sum = s;
    }
};

struct node* sumOfLongRootToLeafPathUtil(Node *root){
    if(root->left == NULL and root->right == NULL)
        return new node(1,root->data);

    node *left = new node(-1,0);
    node *right = new node(-1,0);
    if(root->left)
        left = sumOfLongRootToLeafPathUtil(root->left);
    if(root->right)
        right = sumOfLongRootToLeafPathUtil(root->right);


    int sum;

    if(left->height > right->height)
        sum = left->sum + root->data;
    else if(right->height > left->height)
        sum = right->sum + root->data;
    else
        sum = max(left->sum, right->sum) + root->data;

    return new node(max(left->height,right->height) + 1,sum);
}

int sumOfLongRootToLeafPath(Node* root){
    if(root == NULL) return 0;
    return sumOfLongRootToLeafPathUtil(root)->sum;
}
