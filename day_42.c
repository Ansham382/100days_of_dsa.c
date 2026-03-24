/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.

Input Format:
- First line contains integer N
- Second line contains N space-separated integers

Output Format:
- Print the reversed queue

Example:
Input:
5
10 20 30 40 50

Output:
50 40 30 20 10*/

#include <stdio.h>

#define MAX 100

int main() {
    int queue[MAX], stack[MAX];
    int n;

    // Input
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Push queue elements into stack
    int top = -1;
    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue (reversed)
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    // Output
    printf("Reversed queue:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}
