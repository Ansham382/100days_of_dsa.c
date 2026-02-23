/*Problem: Merge Two Sorted Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print the merged linked list elements, space-separated

Example:
Input:
5
10 20 30 40 50
4
15 25 35 45

Output:
10 15 20 25 30 35 40 45 50

Explanation:
Compare nodes of both lists, append smaller to result, continue until all nodes are merged.*/
#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Create new node
struct node* create(int x) {
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

// Insert at end
struct node* insert(struct node *head, int x) {
    struct node *temp = create(x);

    if(head == NULL)
        return temp;

    struct node *p = head;
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
    return head;
}

// Merge two sorted lists
struct node* merge(struct node *a, struct node *b) {
    struct node *result = NULL, *last = NULL;

    if(a == NULL) return b;
    if(b == NULL) return a;

    // first node
    if(a->data < b->data) {
        result = last = a;
        a = a->next;
    } else {
        result = last = b;
        b = b->next;
    }

    // compare remaining
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            last->next = a;
            last = a;
            a = a->next;
        } else {
            last->next = b;
            last = b;
            b = b->next;
        }
    }

    // attach remaining
    if(a != NULL) last->next = a;
    if(b != NULL) last->next = b;

    return result;
}

// Print list
void print(struct node *head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, m, x;
    struct node *l1 = NULL, *l2 = NULL, *ans;

    // first list
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        l1 = insert(l1,x);
    }

    // second list
    scanf("%d",&m);
    for(int i=0;i<m;i++) {
        scanf("%d",&x);
        l2 = insert(l2,x);
    }

    ans = merge(l1,l2);

    print(ans);

    return 0;
}
