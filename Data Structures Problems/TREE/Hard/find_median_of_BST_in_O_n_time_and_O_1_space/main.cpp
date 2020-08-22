#include<bits/stdc++.h>
using namespace std;

/* A binary search tree Node has data, pointer
   to left child and a pointer to right child */
struct Node
{
    int data;
    struct Node* left, *right;
};

// A utility function to create a new BST node
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with
   given key in BST */
struct Node* insert(struct Node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}

/* Function to count nodes in a  binary search tree
   using Morris Inorder traversal*/



/* Function to find median in O(n) time and O(1) space
   using Morris Inorder traversal*/

int countNodes(struct Node *root){
    Node *current=root,*pre=NULL;
    int n=0;

    while(current != NULL){
        if(current->left == NULL){
            n++;
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right != NULL and pre->right != current)
                pre = pre->right;

            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }else{
                pre->right = NULL;
                n++;
                current = current->right;
            }
        }
    }

    return n;
}

int findMedian(struct Node *root){
    int n = countNodes(root);

    int median_index;
    if(n % 2 == 0)
        median_index = (n/2 + (n+1)/2)/2;
    else
        median_index = (n+1)/2;

    n = 1;

    Node* current = root;
    Node* pre = NULL;

    while(current != NULL){
        if(current->left == NULL){
            if(n == median_index)
                return current->data;
            n++;
            current = current->right;
        }else{
            pre = current->left;
            while(pre->right != NULL and pre->right != current){
                pre = pre->right;
            }

            if(pre->right == NULL){
                pre->right = current;
                current = current->left;
            }else{
                if(n == median_index)
                    return current->data;
                n++;
                current = current->right;
            }
        }
    }


}

/* Driver program to test above functions*/
int main()
{

    /* Let us create following BST
                  50
               /     \
              30      70
             /  \    /  \
           20   40  60   80 */
    struct Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    insert(root, 55);
    insert(root, 51);
    insert(root, 1);

    cout << "\nMedian of BST is "
         << findMedian(root) << endl;
    return 0;
}















//if(root == NULL)
//    return 0;

//int count=0;
//Node* current = root;
//Node* pre = NULL;

//while(current->left or current->right){
//    if(current->left){
//        if(pre->data < current->data){
//            pre->right = NULL;
//        }else if(not pre or pre->data > current->data){
//            Node *predecessor = current->left;
//            while(predecessor->right != NULL){
//                predecessor = predecessor->right;
//            }

//            predecessor->right = current;
//            pre = current;
//            current = current->left;
//        }

//        else if(pre->data < current->left->data){

//        }

//    }else{
//        count++;
//        pre = current;
//        current = current->right;
//    }
//}
