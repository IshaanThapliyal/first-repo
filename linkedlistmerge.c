#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *h1 = NULL;
struct node *h2 = NULL;
struct node *head = NULL;
void input(){
    int n, x;
    struct node *newNode, *temp;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = x;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        } else{
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
}

void display() {
    struct node *temp = head;
    if(temp == NULL){
        printf("List is empty.\n");
        return;
    }
    printf("The elements are: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node* merge(struct node* h1, struct node* h2){
    struct node*tail=NULL;
    if(h1->data < h2->data){
        head = tail = h1;
        h1 = h1->next;
    } else{
        head = tail = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL){
        if(h1->data < h2->data){
            tail->next = h1;
            tail = h1;
            h1 = h1->next;
        } else{
            tail->next = h2;
            tail = h2;
            h2 = h2->next;
        }
    }
    if(h1 != NULL) tail->next = h1;
    if(h2 != NULL) tail->next = h2;
    return head;
}

int main(){
    head = NULL;
    input();
    h1 = head;
    printf("First List: ");
    display();
    head = NULL;
    input();
    h2 = head;
    printf("Second List: ");
    display();
    struct node *mergedList = merge(h1, h2);
    head = mergedList;
    printf("Merged list: ");
    display();
    return 0;
}
