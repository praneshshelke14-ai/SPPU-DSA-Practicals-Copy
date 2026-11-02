/* Practical 8: Binary Search Tree operations in C */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* mirrored == 0: normal BST; mirrored == 1: left/right ordering is reversed. */
Node* insert(Node* root, int value, int mirrored) {
    if (root == NULL) return createNode(value);

    if ((!mirrored && value < root->data) || (mirrored && value > root->data)) {
        root->left = insert(root->left, value, mirrored);
    } else if ((!mirrored && value > root->data) || (mirrored && value < root->data)) {
        root->right = insert(root->right, value, mirrored);
    }
    /* Duplicate values are ignored. */
    return root;
}

int height(Node* root) {
    if (root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

int minimumValue(Node* root, int mirrored) {
    if (mirrored) {
        while (root->right != NULL) root = root->right;
    } else {
        while (root->left != NULL) root = root->left;
    }
    return root->data;
}

void mirrorTree(Node* root) {
    if (root == NULL) return;
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorTree(root->left);
    mirrorTree(root->right);
}

Node* search(Node* root, int value, int mirrored) {
    if (root == NULL || root->data == value) return root;

    if ((!mirrored && value < root->data) || (mirrored && value > root->data))
        return search(root->left, value, mirrored);
    return search(root->right, value, mirrored);
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void) {
    Node* root = NULL;
    int n, value, choice;
    int mirrored = 0;

    printf("Enter number of initial nodes: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter values: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value, mirrored);
    }

    do {
        printf("\n--- BINARY SEARCH TREE ---\n");
        printf("1. Insert Node\n2. Nodes in Longest Path\n3. Minimum Value\n");
        printf("4. Swap Left and Right Pointers\n5. Search Value\n6. Display Inorder\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value, mirrored);
                break;
            case 2:
                printf("Nodes in longest path (height): %d\n", height(root));
                break;
            case 3:
                if (root == NULL) printf("Tree is empty.\n");
                else printf("Minimum value: %d\n", minimumValue(root, mirrored));
                break;
            case 4:
                mirrorTree(root);
                mirrored = !mirrored;
                printf("Left and right pointers swapped at every node.\n");
                break;
            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value, mirrored) != NULL) printf("Value found.\n");
                else printf("Value not found.\n");
                break;
            case 6:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 0:
                printf("Exiting.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    freeTree(root);
    return 0;
}
