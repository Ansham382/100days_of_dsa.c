/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = x;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        top--;
    }
}

void display() {
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main() {
    int n, m, x;

    printf("Enter number of elements to push: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        push(x);
    }

    printf("Enter number of pops: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        pop();
    }

    printf("Remaining stack elements (top to bottom): ");
    display();

    return 0;
}
