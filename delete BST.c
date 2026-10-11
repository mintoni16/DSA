
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

struct Node* minValue(struct Node* root) {
    struct Node* current = root;

    while (current != NULL && current->left != NULL) {
        current = current->left;
    }

    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        else {
            struct Node* temp = minValue(root->right);

            root->data = temp->data;

            root->right = deleteNode(root->right, temp->data);
        }
    }

    return root;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    printf("\nBST before deletion: ");
    inorder(root);

    printf("\nEnter element to delete: ");
    scanf("%d", &key);

    root = deleteNode(root, key);

    printf("\nBST after deletion: ");
    inorder(root);

    printf("\n");

    return 0;
}
