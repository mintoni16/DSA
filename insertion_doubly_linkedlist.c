#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node* next;
};
struct Node *head = NULL;

void insertionBeginning(int data){
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertEnd(int data){
    struct Node *newNode;
    struct Node *temp;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if (head==NULL){
        newNode->prev = NULL;
        head = newNode;
    }
    temp = head;
    while(temp->next != NULL ){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertPosition(int data , int position){
    struct Node *newNode;
    struct Node *temp;
    int i;
    newNode = (struct Node *) malloc (sizeof(struct Node));
    newNode->data = data;
    if (position == 1){
        newNode->prev = NULL;
        newNode->next = head;
        head = newNode;
    }
    temp = NULL;
    for (i = 1; i<position && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("invalid");
        return;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
    temp->next = newNode;
}

void forwardDisplay(){
    struct Node *temp = head;

    printf("Forward: ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

void backwardDisplay(){
    struct Node *temp = head;

    if(head == NULL){
        printf("List is empty\n");
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    printf("Backward: ");

    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }

    printf("\n");
}

int main(){

    insertionBeginning(10);
    insertionBeginning(20);
    insertionBeginning(30);

    insertEnd(40);
    insertEnd(50);

    forwardDisplay();
    backwardDisplay();

    return 0;
}