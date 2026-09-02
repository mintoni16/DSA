#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int data) {
    struct Node *newnode;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void insertEnd(int data) {
    struct Node *newnode;
    struct Node *temp;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}

void insertPosition(int data, int position) {
    struct Node *newnode;
    struct Node *temp;
    int i;

    newnode = (struct Node *)malloc(sizeof(struct Node));

    newnode->data = data;

    if (position == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void display() {
    struct Node *temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {

    insertBeginning(20);
    insertBeginning(10);

    insertEnd(40);
    insertEnd(50);

    insertPosition(30, 3);

    display();

    return 0;
}