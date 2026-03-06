/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    int val;
    struct Node* temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }

    temp = top;
    val = top->data;
    top = top->next;
    free(temp);

    return val;
}

int main() {
    int a, b, result;
    char exp[100];
    int i = 0;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    while (exp[i] != '\0') {

        if (exp[i] >= '0' && exp[i] <= '9') {
            push(exp[i] - '0');
        }

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            b = pop();
            a = pop();

            if (exp[i] == '+') result = a + b;
            if (exp[i] == '-') result = a - b;
            if (exp[i] == '*') result = a * b;
            if (exp[i] == '/') result = a / b;

            push(result);
        }

        i++;
    }

    printf("Result = %d", pop());

    return 0;
}
