/* C++ program to construct a binary tree from
   the given string */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

/* This funtcion is here just to test  */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// function to construct tree from string
Node* treeFromString(string str){
    stack<Node*> st1;

    Node* node = newNode(int(str[0]) - '0');
    st1.emplace(node);

    int i=1;
    while(i < str.size()){
        if(str[i] == '('){
            i++;
            st1.emplace(newNode(int(str[i]) - '0'));
        }else if(str[i] == ')'){
            i++;
            Node *top = st1.top();st1.pop();
            if(not st1.top()->left){
                st1.top()->left = top;
            }else{
                st1.top()->right = top;
            }
        }else
            i++;
    }

    return node;
}



// Driver Code
int main()
{
    string str = "4(2(3(4(6(7(8(8)))))))(6(5))";
    Node* root = treeFromString(str);
    preOrder(root);
}
