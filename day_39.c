/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>

#define MAX 100

int heap[MAX];
int size = 0;

// Swap two numbers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Insert into heap
void insert(int value) {
    heap[size] = value;
    int i = size;
    size++;

    // Move up
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Extract minimum
int extractMin() {
    if (size == 0) return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    int i = 0;

    // Move down
    while (2 * i + 1 < size) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = left;

        if (right < size && heap[right] < heap[left])
            smallest = right;

        if (heap[i] > heap[smallest]) {
            swap(&heap[i], &heap[smallest]);
            i = smallest;
        } else {
            break;
        }
    }

    return min;
}

// Peek minimum
int peek() {
    if (size == 0) return -1;
    return heap[0];
}

// Main function
int main() {
    int n;
    printf("Enter number of operations: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int choice;

        printf("\n1. Insert\n2. Extract Min\n3. Peek\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int x;
            printf("Enter value: ");
            scanf("%d", &x);
            insert(x);
        }
        else if (choice == 2) {
            int result = extractMin();
            printf("Extracted Min: %d\n", result);
        }
        else if (choice == 3) {
            int result = peek();
            printf("Min Element: %d\n", result);
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
