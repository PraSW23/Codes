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

void pre_order(struct node * root){

    if (root == NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);

}

bool isBSTUtil(struct node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;
    }

    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    return isBSTUtil(root->left, minValue, root->data) && 
           isBSTUtil(root->right, root->data, maxValue);
}

bool is_BST(struct node* root) {
    // Initially, pass minimum and maximum possible integer values
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

struct node * insert_in_BST(struct node * root, int val){

    struct node * temp = root;

    if (root == NULL)
    {
        return create_node(val);
    }
    else
    {
        struct node * prev = NULL;
        while (root!=NULL)
        {
            prev = root;
            if (root->data > val)
            {
                
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            
        }
        if (prev->data < val)
        {
            prev->right = create_node(val);
        }else
        {
            prev->left = create_node(val);
        }     
        
    }
    return temp;

}

bool search(struct node * root, int val){
    
        while (root!=NULL)
        {
            if (root->data == val)
            {
                return true;
            }else if (root->data > val)
            {
                root = root->left;
            }else {
                root = root->right;
            }
            
        }
        
    return false;

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

    if (r->left == NULL && r->right)
    {
        return true;
    }
    return false;
    
}

//DEletion needs to be corrected
struct node * Del_in_BST(struct node * root, struct node * temp, int val){


    
    if (root == NULL)
    {
        return NULL;
    }
    
    struct node * prev = NULL;
    while (root!=NULL)
    {
        prev = root;
        if(root->data == val){
            if (is_leaf(root))
            {
                if (prev->data > root->data)
                {
                    prev->left = NULL;
                }else if (prev->data < root->data)
                {
                    prev->right = NULL;
                }  
                return temp;
            }else{
                //replace parent node which is to be deleted with other node 
                struct node * tmp = temp;

                //finding in_order predecer
                tmp = tmp->left;
                while (tmp->right!=NULL)
                {
                    tmp = tmp->right;
                }

                if (is_leaf(tmp))
                {
                    tmp->left = temp->left;
                    tmp->right = temp->right;
                    free(temp);
                    return tmp;
                }
                
                
                //finding in_order sucessor
                struct node * tmp2 = temp->right;
                while (tmp2->left!=NULL)
                {
                    tmp2 = tmp2->left;
                }

                if (is_leaf(tmp2))
                {
                    tmp2->left = temp->left;
                    tmp2->right = temp->right;
                    free(temp);
                    return tmp2;
                }

                return Del_in_BST(tmp, temp, tmp->data);
                
                
            }
            
        }else if (root->data > val)
        {
            root = root->left;
        }else
        {
            root = root->right;
        }
        
        
    }
    

}

int main(){

    struct node * root = form_tree();

    in_order(root);

    if (is_BST(root))
    {
        cout<<"\nYES, it is BST."<<endl;
    }
    else cout<<"\nNO, it is not BST."<<endl;


    int key;
    cout<<"Enter Key to find : ";
    cin>>key;

    if (search(root, key))
    {
        cout<<"Key found"<<endl;
    }
    else cout<<"Key NOT found"<<endl;


    root = insert_in_BST(root, 7);
    in_order(root);
    cout<<endl;

    root = Del_in_BST(root, root, 4);
    in_order(root);
    cout<<endl;

    return 0;
}