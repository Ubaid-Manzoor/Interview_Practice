#include<bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    Node (int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

/* Iterative function for inorder tree
   traversal */
void inOrder(struct Node *root) {
    stack<Node*> s;

    Node *current = root;

    while(current or not s.empty()){

        while(current){
            s.emplace(current);
            current = current->left;
        }

        Node *top = s.top();s.pop();
        cout<<top->data<<" ";
        current = top->right;
    }

}

/* Driver program to test above functions*/
int main()
{

    /* Constructed binary tree is
              1
            /   \
          2      3
        /  \
      4     5
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    inOrder(root);
    return 0;
}
