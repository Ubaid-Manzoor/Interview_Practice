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

void printAllDups(Node* root);

int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
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
           if (root == NULL) root = parent;
        }
        else parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')parent->left = child;
        else parent->right = child;
        m[n2]  = child;
     }
     printAllDups(root);
     cout<<endl;
  }
  return 0;
}// } Driver Code Ends


//function Template for C++

/*
Structure of the node of the binary tree is as
struct Node {
    int data;
    struct Node* left, *right;
};
*/
// you are required to complete this function
// the function should print all the root node of the
// duplicate subtree in non-decreasing order
// need not print a new line

string inOrder(Node* root, vector<int> &max_heap, unordered_map<string,int> &tree_count){
    if(root == NULL)
        return "";

    string tree;
    tree += inOrder(root->left, max_heap , tree_count);
    tree += root->data;
    tree += inOrder(root->right, max_heap , tree_count);

    if(tree_count.find(tree) == tree_count.end()){
        tree_count[tree] = 1;
    }else if(tree_count[tree] != -1){
        max_heap.emplace_back(root->data);
        push_heap(max_heap.begin(), max_heap.end(),greater<int>());
        tree_count[tree] = -1;
    }

    return tree;
}

void printAllDups(Node* root)
{
    // Code here
    vector<int> max_heap;
    make_heap(max_heap.begin(), max_heap.end(), greater<int>());
    unordered_map<string, int> tree_count;

    inOrder(root, max_heap,tree_count);

    if(max_heap.size() == 0){
        cout<<"-1";return;
    }

    for(int node: max_heap){
        cout<<node<<" ";
    }
}


































