#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

/* Create doubly linked list */
void create() {
    int n, i, data;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
}

/* Insert node to the left of a given value */
void insert_left() {
    int key, data;
    struct node *newnode, *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to insert left of: ");
    scanf("%d", &key);

    printf("Enter new data: ");
    scanf("%d", &data);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;

    printf("Node inserted successfully.\n");
}

/* Delete node based on specific value */
void delete_value() {
    int key;
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Enter value to delete: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted element: %d\n", temp->data);
    free(temp);
}

/* Display doubly linked list */
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List:\n");
    temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create List\n");
        printf("2. Insert Left of a Node\n");
        printf("3. Delete by Value\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_left(); break;
            case 3: delete_value(); break;
            case 4: display(); break;
            case 5: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
