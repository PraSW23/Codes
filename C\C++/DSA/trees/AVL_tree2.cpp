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
   
   return 1 + max(height(root->left), height(root->right));


}



bool is_AVL(struct node * root){

    int lh;
    int rh;

    if (root==NULL)
    {
        return true;
    }

    lh = height(root->left);
    rh = height(root->right);

    if (abs(lh - rh) <= 1 && is_AVL(root->left) && is_AVL(root->right))
    {
        return true;
    }

    return false;
        
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