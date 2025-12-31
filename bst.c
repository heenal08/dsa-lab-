#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create new node */
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

/* Insert into BST */
struct node* insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

/* In-order Traversal */
void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/* Preorder Traversal */
void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

/* Postorder Traversal */
void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    struct node *root = NULL;
    int n, i, data, choice;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert(root, data);
    }

    while (1) {
        printf("\n--- BST Traversal Menu ---\n");
        printf("1. In-order Traversal\n");
        printf("2. Preorder Traversal\n");
        printf("3. Postorder Traversal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-order Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 2:
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 3:
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 4:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}
