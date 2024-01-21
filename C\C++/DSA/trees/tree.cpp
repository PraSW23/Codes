#include<iostream>
using namespace std;

struct node{
    int data;
    struct node * left;
    struct node * right;   
};

struct node * create_node(int data){

    //struct node * n = (struct node *)malloc(sizeof(struct node));
    struct node* n = new node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;

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

//pre-order traversal
void traverse(struct node * root){

     if (root == NULL) {
        return;
    }

    cout << root->data << endl;

    traverse(root->left);
    traverse(root->right);


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
struct node * root = NULL;
root = form_tree();

 cout << "\nTree Structure:(rotate screen)\n";
    printTreeStructure(root, 0);

return 0;

}