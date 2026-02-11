#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct Node{
    int data;
    struct Node *left, *right;
};

struct Stack{
    int top;
    int size;
    struct Node** arr;
};

struct Node* createNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data){
    struct Node* newNode = createNode(data);
    if(!root){
        return newNode;
    }
    struct Node* curr = root;
    struct Node* parent = NULL;
    while (curr != NULL){
        parent = curr;
        if(data < curr->data){
            curr = curr->left;
        } else if(data > curr->data){
            curr = curr->right;
        } else{
            return root;
        }
    }
    if(data < parent->data){
        parent->left = newNode;
    } else{
        parent->right = newNode;
    }
    return root;
}

void push(struct Stack* s, struct Node* x){
    if(s->top == s->size - 1){
        printf("Stack full\n");
        return;
    }
    s->arr[++s->top] = x;
}

struct Node* pop(struct Stack* s){
    if(s->top == -1){
        printf("Stack empty\n");
        return NULL;
    }
    return s->arr[s->top--];
}

void inorder(struct Node* root, struct Stack* s) {
    while(root != NULL || s->top != -1){
        while(root != NULL){
            push(s, root);
            root = root->left;
        }
        root = pop(s);
        printf("%d ", root->data);
        root = root->right;
    }
}

void preorder(struct Node* root, struct Stack* s){
    if (!root) return;
    push(s, root);
    while (s->top != -1) {
        root = pop(s);
        printf("%d ", root->data);
        if(root->right) push(s, root->right);
        if(root->left) push(s, root->left);
    }
}

void postorder(struct Node* root, struct Stack* s){
    if (root == NULL) return;
    struct Stack stk;
    stk.size = MAX;
    stk.top = -1;
    stk.arr = (struct Node**)malloc(stk.size * sizeof(struct Node*));
    push(s, root);
    while(s->top != -1){
        root = pop(s);
        push(&stk, root);
        if(root->left) push(s, root->left);
        if(root->right) push(s, root->right);
    }
    while(stk.top != -1){
        root = pop(&stk);
        printf("%d ", root->data);
    }
    free(stk.arr);
}

int main(){
    struct Stack s;
    s.size = MAX;
    s.top = -1;
    s.arr = (struct Node**)malloc(s.size * sizeof(struct Node*));
    int n, data;
    struct Node* root = NULL;
    printf("Number of nodes? ");
    scanf("%d", &n);
    printf("Enter values: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("\n-----INORDER-----\n");
    inorder(root, &s);
    printf("\n-----PREORDER-----\n");
    preorder(root, &s);
    printf("\n-----POSTORDER-----\n");
    postorder(root, &s);
    free(s.arr);
    return 0;
}
