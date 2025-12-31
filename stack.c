#include <stdio.h>
#define MAX 5   // Stack size

int stack[MAX];
int top = -1;

/* Push operation */
void push() {
    int item;
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push.\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &item);
    stack[++top] = item;
    printf("Element %d pushed successfully.\n", item);
}

/* Pop operation */
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    printf("Popped element: %d\n", stack[top--]);
}

/* Display operation */
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements are:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting program.\n");
                    return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

