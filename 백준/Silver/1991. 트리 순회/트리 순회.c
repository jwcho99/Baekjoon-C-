#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char alpha;
    struct _node* left;
    struct _node* right;
}node;

node* createNode(char alpha){
    node* newNode = (node*)malloc(sizeof(node));
    newNode->alpha = alpha;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void connect_node(node* root, node* new_node){
    if(root->left!=NULL){
        if(root->left->alpha == new_node->alpha){
            free(root->left);
            root->left = new_node;
        }
        else connect_node(root->left, new_node);
    }
    if(root->right!=NULL){
        if(root->right->alpha == new_node->alpha){
            free(root->right);
            root->right = new_node;
        }
        else connect_node(root->right, new_node);
    }

    /* if(root->left == NULL) return;
    if(root->left->alpha == new_node->alpha){
        free(root->left);
        root->left = new_node;
        return;
    }
    if(root->right == NULL) return;
    if(root->right->alpha == new_node->alpha){
        free(root->right);
        root->right = new_node;
        return;
    }
    connect_node(root->left, new_node);
    connect_node(root->right, new_node);
    return; */
}

void preorder(node* root){
    if(root == NULL) return;
    printf("%c", root->alpha);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    printf("%c", root->alpha);
    inorder(root->right);
}

void postorder(node* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%c", root->alpha);
}

int main(){
    int n;
    scanf("%d", &n);
    node* root = NULL;

    for(int i=0;i<n;i++){
        char parent, left, right;
        scanf(" %c %c %c", &parent, &left, &right);
        node* new_node = createNode(parent);
        if(i==0) root = new_node;
        if(left != '.') new_node->left = createNode(left);
        if(right != '.') new_node->right = createNode(right);

        connect_node(root, new_node);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    return 0;
}