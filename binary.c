#include <stdio.h>
#include <stdlib.h>

// Structure of a node
struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Insert a node into BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        printf("Duplicate values are not allowed.\n");

    return root;
}

// Inorder: Left, Root, Right
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder: Root, Left, Right
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder: Left, Right, Root
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Level Order: Uses a queue
void levelOrder(struct Node* root) {
    if (root == NULL) {
        printf("Tree is empty.");
        return;
    }

    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];
        printf("%d ", current->data);

        if (current->left != NULL)
            queue[rear++] = current->left;

        if (current->right != NULL)
            queue[rear++] = current->right;
    }
}

// Free allocated memory
void freeTree(struct Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    struct Node* root = NULL;
    int n, value, choice, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n < 0 || n > 1000) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    printf("Enter %d values:\n", n);

    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    do {
        printf("\n\n--- BINARY SEARCH TREE MENU ---\n");
        printf("1. Inorder Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Level Order Traversal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("Level Order: ");
                levelOrder(root);
                printf("\n");
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    freeTree(root);

    return 0;
}