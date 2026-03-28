/*Problem: Level Order Traversal

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Queue for level order
struct Node* queue[100];
int front = -1, rear = -1;

// Enqueue
void enqueue(struct Node* node) {
    if (rear == 99) return;
    if (front == -1) front = 0;
    queue[++rear] = node;
}

// Dequeue
struct Node* dequeue() {
    if (front == -1 || front > rear) return NULL;
    return queue[front++];
}

// Level Order Traversal
void levelOrder(struct Node* root) {
    if (root == NULL) return;

    enqueue(root);

    while (front <= rear) {
        struct Node* temp = dequeue();
        printf("%d ", temp->data);

        if (temp->left != NULL)
            enqueue(temp->left);

        if (temp->right != NULL)
            enqueue(temp->right);
    }
}

int main() {
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    if (n == 0) return 0;

    struct Node* nodes[100];

    // Input nodes
    for (int i = 0; i < n; i++) {
        printf("Enter value of node %d: ", i + 1);
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    // Link nodes as binary tree
    for (int i = 0; i < n; i++) {
        int leftIndex = 2*i + 1;
        int rightIndex = 2*i + 2;

        if (leftIndex < n)
            nodes[i]->left = nodes[leftIndex];

        if (rightIndex < n)
            nodes[i]->right = nodes[rightIndex];
    }

    printf("Level Order Traversal: ");
    levelOrder(nodes[0]);

    return 0;
}
