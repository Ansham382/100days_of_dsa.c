/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/
#include <stdio.h>

int main() {
    int n, target, i, comparisons = 0;
    
    // Get array size
    if (scanf("%d", &n) != 1) return 0;
    
    int a[n];
    
    // Fill the array
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // Get the value to search for
    scanf("%d", &target);
    
    for(i = 0; i < n; i++) {
        comparisons++; // Increment before checking
        if(a[i] == target) {
            printf("Found at index %d\n", i);
            printf("Comparisons = %d\n", comparisons);
            return 0;
        }
    }
    
    // If loop finishes without returning, the value isn't there
    printf("Not Found\n");
    printf("Comparisons = %d\n", comparisons);
    
    return 0;
}
