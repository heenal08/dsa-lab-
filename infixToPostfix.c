#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/* Push to stack */
void push(char ch) {
    stack[++top] = ch;
}

/* Pop from stack */
char pop() {
    return stack[top--];
}

/* Return precedence of operator */
int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter valid infix expression: ");
    scanf("%s", infix);

    while ((ch = infix[i++]) != '\0') {

        /* If operand, add to postfix */
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }

        /* If '(', push to stack */
        else if (ch == '(') {
            push(ch);
        }

        /* If ')', pop till '(' */
        else if (ch == ')') {
            while (stack[top] != '(')
                postfix[k++] = pop();
            pop();  // remove '('
        }

        /* If operator */
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
