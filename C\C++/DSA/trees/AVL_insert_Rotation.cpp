//AVL have three rotations 
//LL, RR, LR , RL rotations

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

//with bottom up recursion
struct node * AVL_conversion(struct node * root){

    if (root == NULL)
    {
        return NULL;
    }

    root->left = AVL_conversion(root->left);
    root->right = AVL_conversion(root->right);

    int hd = height(root->left) - height(root->right);

    if (abs(hd) == 1 || hd == 0)
    {
        return root;
    }

    if (hd == 2)
    {
        // LL rotation
        if (root->left->left != NULL)
        {
            struct node * tmp = root->left;
            tmp->right = root;
            root->left = NULL;
            return tmp;
        }else{
            //LR rotation
            struct node * tmp = root->left;
            root->left = tmp->right;
            root->left->left = tmp;
            tmp->right = NULL;
            
            tmp = root->left;
            tmp->right = root;
            root->left = NULL;
            return tmp;
        }

    }

    if (hd == -2)
    {
        // RR rotation
        if (root->right->right != NULL)
        {
            struct node * tmp = root->right;
            tmp->left = root;
            root->right = NULL;
            return tmp;
        }else{
            //RL rotation
            struct node * tmp = root->right;
            root->right = tmp->left;
            root->right->right = tmp;
            tmp->left = NULL;
            
            tmp = root->right;
            tmp->left = root;
            root->right = NULL;
            return tmp;
        }
    }
    
    return root;

}


// Helper function to print spaces
void printSpaces(int n) {
    for (int i = 0; i < n; ++i) {
        cout << " ";
    }
}

// Function to print the binary tree in tree-like structure
void printTreeStructure(struct node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }

    // Increase distance between levels
    space += 5;

    // Process right child first
    printTreeStructure(root->right, space);

    // Print current node after space count
    cout << endl;
    printSpaces(space);
    cout << root->data << "\n";

    // Process left child
    printTreeStructure(root->left, space);
}



int main(){

    struct node * root = form_tree();

    in_order(root);

    if (is_AVL(root))
    {
        cout<<"\nYES, it is AVL tree."<<endl;
    }
    else cout<<"\nNO, it is not AVL tree."<<endl;

    cout << "\nTree Structure:(rotate screen)\n";
    printTreeStructure(root, 0);

    root = AVL_conversion(root);
    if (is_AVL(root))
    {
        cout<<"\nYES, it is AVL tree."<<endl;
    }
    else cout<<"\nNO, it is not AVL tree."<<endl;

    in_order(root);
    cout<<endl;
    cout << "\nTree Structure:(rotate screen)\n";
    printTreeStructure(root, 0);

    return 0;
}