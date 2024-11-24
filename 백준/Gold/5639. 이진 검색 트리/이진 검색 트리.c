#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node* left;
    struct node* right;
}node;

node* make_node(int val){
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int val){
    if(root == NULL){
        return make_node(val);
    }
    if(val < root->value){
        root->left = insert(root->left, val);
    }
    else{
        root->right = insert(root->right, val);
    }
    return root;
}

void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\n", root->value);
}


int main(){
    int n;
    node* root = NULL;
    while(scanf(" %d", &n) != EOF){
        root = insert(root, n);
    }
    postorder(root);
    return 0;
}