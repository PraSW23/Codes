//AVL tree is height balancing BST.

#include<iostream>
#include<climits>
using namespace std;

struct node {
    int data;
    struct node * left;
    struct node * right;

};

struct node * create_node(int data){

struct node * n = new node();
n->data = data;
n->left = n->right = NULL;
return n;

}

struct node * form_tree(){

    int data;
    cin>>data;

    if (data == -1)
    {
        return NULL;
    }

    struct node * n = create_node(data);
    
    n->left = form_tree();
    n->right = form_tree();
    
    return n;

}

void pre_order(struct node * root){

    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);

}


void in_order(struct node * root){

    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}

int height(struct node * root){

    if (root==NULL)
    {
        return 0;
    }
     
    return max(height(root->left), height(root->right)) + 1;

}

bool isAVLUtil(struct node *root, int &minHeight, int &maxHeight) {
    if (root == NULL) {
        minHeight = maxHeight = 0;
        return true;
    }

    int leftMin, leftMax, rightMin, rightMax;
    if (!isAVLUtil(root->left, leftMin, leftMax) || !isAVLUtil(root->right, rightMin, rightMax))
        return false;

    minHeight = min(leftMin, rightMin) + 1;
    maxHeight = max(leftMax, rightMax) + 1;

    if (abs(leftMax - rightMax) > 1)
        return false;

    return true;
}


bool is_AVL(struct node * root){

   int minHeight, maxHeight;
    return isAVLUtil(root, minHeight, maxHeight);
}


int main(){

    struct node * root = form_tree();

    in_order(root);

    if (is_AVL(root))
    {
        cout<<"\nYES, it is AVL tree."<<endl;
    }
    else cout<<"\nNO, it is not AVL tree."<<endl;
    

    return 0;
}