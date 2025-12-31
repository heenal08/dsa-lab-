#include <stdio.h>
#define MAX 5   // Circular queue size

int cq[MAX];
int front = -1, rear = -1;

/* Insert operation */
void insert() {
    int item;

    // Check for overflow
    if ((rear + 1) % MAX == front) {
        printf("Circular Queue Overflow! Cannot insert.\n");
        return;
    }

    // First insertion
    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);
    cq[rear] = item;
    printf("Element %d inserted successfully.\n", item);
}

/* Delete operation */
void delete() {
    // Check for empty
    if (front == -1) {
        printf("Circular Queue is Empty! Cannot delete.\n");
        return;
    }

    printf("Deleted element: %d\n", cq[front]);

    // Single element case
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

/* Display operation */
void display() {
    int i;

    if (front == -1) {
        printf("Circular Queue is Empty.\n");
        return;
    }
   printf("Circular Queue elements are:\n");

    i = front;
    while (1) {
        printf("%d ", cq[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting program.\n");
                    return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
