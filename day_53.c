/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.

Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)

Output Format:
- Print nodes column by column from leftmost to rightmost vertical line

Example:
Input:
7
1 2 3 4 5 6 7

Output:
4
2
1 5 6
3
7

Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/
#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct Node {
    int data;
    int hd; // horizontal distance
    struct Node *left, *right;
};

// Queue Node
struct QNode {
    struct Node* treeNode;
    struct QNode* next;
};

// Queue
struct Queue {
    struct QNode *front, *rear;
};

// Create new tree node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->hd = 0;
    return temp;
}

// Create queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Enqueue
void enqueue(struct Queue* q, struct Node* node) {
    struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
    temp->treeNode = node;
    temp->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Dequeue
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL)
        return NULL;

    struct QNode* temp = q->front;
    struct Node* node = temp->treeNode;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return node;
}

// Build tree from level order
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);

    int i = 1;

    while (i < n) {
        struct Node* curr = dequeue(q);

        // Left child
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        if (i >= n) break;

        // Right child
        if (arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }

    return root;
}

// Simple vertical order using array
void verticalOrder(struct Node* root) {
    if (!root) return;

    int min = 0, max = 0;

    // Queue for BFS
    struct Queue* q = createQueue();
    root->hd = 0;
    enqueue(q, root);

    // First pass: find min and max hd
    while (q->front != NULL) {
        struct Node* temp = dequeue(q);

        if (temp->hd < min) min = temp->hd;
        if (temp->hd > max) max = temp->hd;

        if (temp->left) {
            temp->left->hd = temp->hd - 1;
            enqueue(q, temp->left);
        }
        if (temp->right) {
            temp->right->hd = temp->hd + 1;
            enqueue(q, temp->right);
        }
    }

    // Print vertical order
    for (int line = min; line <= max; line++) {
        struct Queue* q2 = createQueue();
        root->hd = 0;
        enqueue(q2, root);

        while (q2->front != NULL) {
            struct Node* temp = dequeue(q2);

            if (temp->hd == line)
                printf("%d ", temp->data);

            if (temp->left) {
                temp->left->hd = temp->hd - 1;
                enqueue(q2, temp->left);
            }
            if (temp->right) {
                temp->right->hd = temp->hd + 1;
                enqueue(q2, temp->right);
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int n;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter level order (-1 for NULL): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, n);

    printf("\nVertical Order Traversal:\n");
    verticalOrder(root);

    return 0;
}
