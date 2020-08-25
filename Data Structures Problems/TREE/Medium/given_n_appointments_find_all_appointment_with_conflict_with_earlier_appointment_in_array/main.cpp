#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int low,high;
    Interval(int l, int h){
        low = l;high = h;
    }
};

struct Node {
    Interval *I;
    int max;
    Node *left,*right;
};

Node* newNode(int low,int high){
    Node* node = new Node;
    node->I = new Interval(low,high);
    node->max = high;
    node->left = node->right = NULL;

    return node;
}

Node* insert(Node* root, int low,int high){
    if(root == NULL)
        return newNode(low,high);

    if(low < root->I->low)
        root->left = insert(root->left, low, high);
    else
        root->right = insert(root->right, low, high);

    root->max = max(root->max,high);
    return root;
}


bool intervalIntersect(Interval *I1, Interval *I2){
    return (I2->low <= I1->low and I1->low <= I2->high) or (I2->high <= I1->high and I1->high <= I2->high);
}

Interval* searchOverlap(Node* root, Interval *interval){
    if(root == NULL)
        return NULL;

    if(intervalIntersect(interval, root->I))
        return root->I;

    if(not root->left or root->I->low > root->left->max)
        return searchOverlap(root->right, interval);
    else
        return searchOverlap(root->left, interval);
}

void printConflicting(Interval appt[], int n) {
    Interval *I = new Interval(appt[0].low,appt[0].high);
    Node* root = newNode(I->low,I->high);

    for(int i = 1 ; i < n ;i++){
        I = new Interval(appt[i].low,appt[i].high);
        Interval *overlapI = searchOverlap(root, I);
        if(overlapI)
            cout<<"["<<I->low<<","<<I->high<<"]"<<" Overlaps With "<<"["<<overlapI->low<<","<<overlapI->high<<"]"<<endl;
        root = insert(root, I->low, I->high);
    }
}


// Driver program to test above functions
int main()
{
    // Let us create interval tree shown in above figure
    Interval appt[] = { {1, 5}, {3, 7}, {2, 6}, {10, 15},
                        {5, 6}, {4, 100}};
    int n = sizeof(appt)/sizeof(appt[0]);
    cout << "Following are conflicting intervals\n";
    printConflicting(appt, n);
    return 0;
}
