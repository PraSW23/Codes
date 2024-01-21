#include<iostream>
#include <climits>
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

void in_order(struct node * root){

    if (root == NULL)
    {
        return;
    }

    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}


bool is_leaf(struct node * r){

    if (r->left == NULL && r->right == NULL)
    {
        return true;
    }
    return false;
    
}

struct node * Del_in_BST(struct node * root, int val) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data > val) {
        root->left = Del_in_BST(root->left, val);
    } else if (root->data < val) {
        root->right = Del_in_BST(root->right, val);
    } else {
        if (is_leaf(root)) {
            delete root;
            return NULL;
        } else if (root->left == NULL) {
            struct node *temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            delete root;
            return temp;
        } else {
            // Finding inorder successor (smallest node in right subtree)
            struct node *temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            // Copy the inorder successor's data to this node
            root->data = temp->data;

            // Delete the inorder successor
            root->right = Del_in_BST(root->right, temp->data);
        }
    }
    return root;
}


int main() {
    struct node *root = form_tree();

    in_order(root);
    root = Del_in_BST(root, 4);
    cout << "\nAfter deletion:\n";
    in_order(root);
    cout << endl;

    return 0;
}
