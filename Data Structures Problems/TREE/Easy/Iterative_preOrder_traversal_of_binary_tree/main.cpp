#include <bits/stdc++.h>

using namespace std;

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node with the given data and
   NULL left and right  pointers.*/
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// An iterative process to print preorder traversal of Binary tree
void iterativePreorder(node *root)
{
    if(root == NULL)
        return;

    stack<node*> s;
    s.emplace(root);

    while(not s.empty()){
        node *top = s.top();s.pop();
        cout<<top->data<<" ";

        if(top->right)
            s.emplace(top->right);
        if(top->left)
            s.emplace(top->left);
    }


}

void iterativePreorder_(node *root){
    if(root == NULL)
        return;

    stack<node*> s;
    node * current = root;

    while(current or not s.empty()){
            while(current){
                cout<<current->data<<" ";
                s.emplace(current);
                current = current->left;
            }

            while(not s.empty() and not s.top()->right )
                s.pop();

            if(not s.empty()){
                current = s.top()->right;
                s.pop();
            }else
                current = NULL;
    }
}

// Driver program to test above functions
int main()
{
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newNode(10);
  root->left        = newNode(8);
  root->right       = newNode(2);
  root->left->left  = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  root->right->left->right = newNode(33);
  iterativePreorder_(root);
  return 0;
}





















