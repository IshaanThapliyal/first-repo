#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Stack {
    int top;
    int size;
    struct Node **arr;
};

// Initialize stack
void initStack(struct Stack *s, int size) {
    s->size = size;
    s->top = -1;
    s->arr = malloc(size * sizeof(struct Node*));

    if (s->arr == NULL) {
        printf("Memory allocation failed for stack\n");
        exit(1);
    }
}

// Free stack memory
void freeStack(struct Stack *s) {
    free(s->arr);
}

// Push node onto stack
void push(struct Stack *s, struct Node *x) {
    if (s->top == s->size - 1) {
        printf("Stack overflow\n");
        return;
    }
    s->arr[++s->top] = x;
}

// Pop node from stack
struct Node* pop(struct Stack *s) {
    if (s->top == -1) {
        return NULL;
    }
    return s->arr[s->top--];
}

// Create new node
struct Node* createNode(int data) {
    struct Node* node = malloc(sizeof(struct Node));

    if (node == NULL) {
        printf("Memory allocation failed for node\n");
        exit(1);
    }

    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert node
struct Node* insert(struct Node* root, int data) {
    struct Node* newNode = createNode(data);

    if (root == NULL)
        return newNode;

    struct Node* curr = root;
    struct Node* parent = NULL;

    while (curr != NULL) {
        parent = curr;

        if (data < curr->data)
            curr = curr->left;
        else if (data > curr->data)
            curr = curr->right;
        else {
            free(newNode);
            return root;
        }
    }

    if (data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    return root;
}

// Inorder
void inorder(struct Node* root, struct Stack* s) {
    s->top = -1;   // reset stack

    while (root != NULL || s->top != -1) {
        while (root != NULL) {
            push(s, root);
            root = root->left;
        }

        root = pop(s);
        printf("%d ", root->data);
        root = root->right;
    }
}

// Preorder
void preorder(struct Node* root, struct Stack* s) {
    if (!root) return;

    s->top = -1;   // reset stack
    push(s, root);

    while (s->top != -1) {
        root = pop(s);
        printf("%d ", root->data);

        if (root->right) push(s, root->right);
        if (root->left)  push(s, root->left);
    }
}

// Postorder
void postorder(struct Node* root, struct Stack* s) {
    if (!root) return;

    s->top = -1;   // reset stack

    struct Stack s2;
    initStack(&s2, s->size);

    push(s, root);

    while (s->top != -1) {
        root = pop(s);
        push(&s2, root);

        if (root->left)  push(s, root->left);
        if (root->right) push(s, root->right);
    }

    while (s2.top != -1) {
        root = pop(&s2);
        printf("%d ", root->data);
    }

    freeStack(&s2);
}

void freeTree(struct Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int n, data;
    struct Node* root = NULL;

    printf("Number of nodes? ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return 0;
    }

    struct Stack s;
    initStack(&s, n);   // stack size = number of nodes

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\n----- INORDER -----\n");
    inorder(root, &s);

    printf("\n----- PREORDER -----\n");
    preorder(root, &s);

    printf("\n----- POSTORDER -----\n");
    postorder(root, &s);

    // Free all memory
    freeTree(root);
    freeStack(&s);

    return 0;
}

