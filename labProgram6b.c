#include <stdio.h>
#include <stdlib.h>

/* Node structure */
struct node {
    int data;
    struct node *next;
};

/* Stack & Queue pointers */
struct node *top = NULL;      // Stack top
struct node *front = NULL;    // Queue front
struct node *rear = NULL;     // Queue rear

/* ---------- STACK OPERATIONS ---------- */

/* Push */
void push() {
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element to push: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = top;
    top = newnode;

    printf("Element pushed successfully.\n");
}

/* Pop */
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", temp->data);
    top = top->next;
    free(temp);
}

/* Display Stack */
void display_stack() {
    struct node *temp = top;

    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- QUEUE OPERATIONS ---------- */

/* Enqueue */
void enqueue() {
    int data;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter element to enqueue: ");
    scanf("%d", &data);

    newnode->data = data;
    newnode->next = NULL;

    if (front == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Element enqueued successfully.\n");
}

/* Dequeue */
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue is empty! Cannot dequeue.\n");
        return;
    }

    temp = front;
    printf("Dequeued element: %d\n", temp->data);
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
}

/* Display Queue */
void display_queue() {
    struct node *temp = front;

    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/* ---------- MAIN MENU ---------- */
int main() {
    int choice;

    while (1) {
        printf("\n--- Stack & Queue using Linked List ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display_stack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: display_queue(); break;
            case 7: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}
