#include <stdio.h>
#include <stdlib.h>
struct Node{
    int val;
    struct Node *left, *right;
};

struct Node* createNode(int val){
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->val = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* insert(struct Node* root, int val){
    if (!root)
        return createNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

void inorder(struct Node* root){
    if(!root)
        return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(!root)
        return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node* root){
    if(!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main(){
    int number,i,val;
    struct Node* root=NULL;
    printf("Enter the number of nodes: ");
    scanf("%d",&number);
    printf("Enter the values: ");
    for(i=0;i<number;i++){
        scanf("%d",&val);
        root=insert(root, val);
    }
    printf("\n-----INORDER-----\n");
    inorder(root);
    printf("\n-----PREORDER-----\n");
    preorder(root);
    printf("\n-----POSTORDER-----\n");
    postorder(root);
}
