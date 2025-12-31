#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

struct node *head1 = NULL, *head2 = NULL;

/* Create linked list */
struct node* create(struct node *head) {
    int n, i, data;
    struct node *temp, *newnode;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        } else {
            temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newnode;
        }
    }
    return head;
}

/* Display linked list */
void display(struct node *head) {
    struct node *temp = head;

    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* Sort linked list (Bubble Sort) */
void sort(struct node *head) {
    struct node *i, *j;
    int temp;

    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("Linked list sorted.\n");
}

/* Reverse linked list */
struct node* reverse(struct node *head) {
    struct node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    printf("Linked list reversed.\n");
    return prev;
}

/* Concatenate two linked lists */
struct node* concatenate(struct node *head1, struct node *head2) {
    struct node *temp;

    if (head1 == NULL)
        return head2;

    temp = head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Linked lists concatenated.\n");
    return head1;
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create List 1\n");
        printf("2. Create List 2\n");
        printf("3. Display List 1\n");
        printf("4. Display List 2\n");
        printf("5. Sort List 1\n");
        printf("6. Reverse List 1\n");
        printf("7. Concatenate List 1 and List 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: head1 = create(head1); break;
            case 2: head2 = create(head2); break;
            case 3: display(head1); break;
            case 4: display(head2); break;
            case 5: sort(head1); break;
            case 6: head1 = reverse(head1); break;
            case 7: head1 = concatenate(head1, head2); break;
            case 8: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
