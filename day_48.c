/*Problem: Count Leaf Nodes

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// Structure for tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build tree using user input
struct Node* buildTree() {
    int data;
    printf("Enter data (-1 for no node): ");
    scanf("%d", &data);

    if (data == -1)
        return NULL;

    struct Node* root = createNode(data);

    printf("Enter left child of %d\n", data);
    root->left = buildTree();

    printf("Enter right child of %d\n", data);
    root->right = buildTree();

    return root;
}

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    // If both children are NULL, it's a leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    printf("Build the binary tree:\n");
    struct Node* root = buildTree();

    int leafCount = countLeafNodes(root);

    printf("Number of leaf nodes = %d\n", leafCount);

    return 0;
}
