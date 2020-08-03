/* Iterative program to check if two trees are level
   by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    struct Node *left, *right;
    int data;
};

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node *root1, Node *root2) {
    if(root1 == NULL and root2 == NULL)
        return true;
    if(root1 == NULL or root2 == NULL)
        return false;

    if(root1->data != root2->data)
        return false;

    queue<Node*> q1,q2;

    q1.emplace(root1);q2.emplace(root2);
    int level_count1 = 1, level_count2 = 1;

    while( (not q1.empty()) and (not q2.empty()) ){
        unordered_map<int,int> counter1,counter2;

        // FOR FIRST TREE
        int temp_count=0;
        while(level_count1--){
            Node * front = q1.front();
            if(front->left != NULL){
                q1.emplace(front->left);temp_count++;
                if(counter1.find(front->left->data) == counter1.end())
                    counter1[front->left->data] = 1;
                else
                    counter1[front->left->data]++;
            }

            if(front->right != NULL){
                q1.emplace(front->right);temp_count++;
                if(counter1.find(front->right->data) == counter1.end())
                    counter1[front->right->data] = 1;
                else
                    counter1[front->right->data]++;
            }

            q1.pop();
        }
        level_count1 = temp_count;


        // FOR SECOND TREE
        temp_count = 0;
        while(level_count2--){
            Node * front = q2.front();
            if(front->left != NULL){
                q2.emplace(front->left);temp_count++;
                if(counter2.find(front->left->data) == counter2.end())
                    counter2[front->left->data] = 1;
                else
                    counter1[front->left->data]++;
            }

            if(front->right != NULL){
                q2.emplace(front->right);temp_count++;
                if(counter2.find(front->right->data) == counter2.end())
                    counter2[front->right->data] = 1;
                else
                    counter2[front->right->data]++;
            }

            q2.pop();
        }
        level_count2 = temp_count;

        if(level_count1 != level_count2)
            return false;

        for(pair<int,int> p:counter1){
            if(counter1[p.first] != counter2[p.first])
                return false;
        }
    }
    return true;

}

// Utility function to create a new tree Node
Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
    root1->right->right->left = newNode(54);
    root1->right->right->right = newNode(35);

    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
    root2->left->right->left = newNode(54);
    root2->left->right->right = newNode(35);

    areAnagrams(root1, root2)? cout << "Yes" <<endl: cout << "No" <<endl;
    return 0;
}
