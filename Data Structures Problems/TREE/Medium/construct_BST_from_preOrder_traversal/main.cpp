#include <bits/stdc++.h>
using namespace std;


/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
    public:
    int data;
    node *left;
    node *right;
};

// A utility function to create a node
node* newNode (int data)
{
    node* temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

node *constructTreeUtil(int pre[], int &preIndex, int data, int int_min, int int_max, int size){
    if(preIndex >= size)
        return NULL;


    node* root = NULL;
    if(int_min < data and data < int_max){
        root = newNode(data);
        preIndex++;
        if(preIndex < size){
            root->left = constructTreeUtil(pre, preIndex, pre[preIndex], int_min, data, size);
            root->right = constructTreeUtil(pre, preIndex, pre[preIndex], data, int_max, size);
        }
    }

    return root;
}

node *constructTree (int pre[], int size){
    int preIndex=0;
    return constructTreeUtil(pre, preIndex, pre[0], INT_MIN, INT_MAX, size);
}

// A utility function to print inorder
// traversal of a Binary Tree
void printInorder (node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

// Driver code
int main ()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof( pre ) / sizeof( pre[0] );

    node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}




//node* root=NULL;
//if(int_min < data and data < int_max){
//     root = newNode(data);
//}

//if(preIndex + 1 < size){
//    if(int_min < pre[preIndex + 1] and pre[preIndex + 1] < data){
//        preIndex++;
//        root->left = constructTreeUtil(pre, preIndex, pre[preIndex], int_min, data, size);
//    }
//    if((preIndex + 1 < size) and data < pre[preIndex + 1] and pre[preIndex + 1] < int_max){
//        preIndex++;
//        root->right = constructTreeUtil(pre, preIndex, pre[preIndex], data, int_max, size);
//    }
//}


//return root;
