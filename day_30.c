/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};

// Create new node
struct Node* createNode(int c, int e) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coef = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insert(struct Node* head, int c, int e) {
    struct Node* temp = createNode(c, e);

    if (head == NULL)
        return temp;

    struct Node* p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

// Print polynomial
void printPoly(struct Node* head) {
    struct Node* p = head;

    while (p != NULL) {
        if (p->exp > 1)
            printf("%dx^%d", p->coef, p->exp);
        else if (p->exp == 1)
            printf("%dx", p->coef);
        else
            printf("%d", p->coef);

        if (p->next != NULL)
            printf(" + ");

        p = p->next;
    }
    printf("\n");
}

int main() {
    int n, c, e;
    struct Node* head = NULL;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &c, &e);
        head = insert(head, c, e);
    }

    printf("Polynomial: ");
    printPoly(head);

    return 0;
}
