#include<iostream>
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

bool is_BST(struct node * root){
    static struct node * prev = NULL;

    if (root !=  NULL)
    {   
        if (!is_BST(root->left))
        {
            return false;
        }
        
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        
        prev = root;

        return is_BST(root->right);

    }else return true;
    

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



int main(){

    struct node * root = form_tree();

    in_order(root);

    if (is_BST(root))
    {
        cout<<"\nYES, it is BST."<<endl;
    }
    else cout<<"\nNO, it is not BST."<<endl;
    

    return 0;
}