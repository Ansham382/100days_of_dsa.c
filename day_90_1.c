/*Problem Statement
Given n boards of different lengths and k painters, each painter paints contiguous boards. Painting a unit length of board takes one unit of time.

Determine the minimum time required to paint all boards.

Input Format
n k
n space-separated integers representing board lengths

Output Format
Print the minimum time required to paint all boards.

Sample Input
4 2
10 20 30 40

Sample Output
60

Explanation
One painter paints boards of length 10, 20, and 30 (total 60), while the other paints board of length 40.*/
#include <stdio.h>

// Check if boards can be painted within given maxTime
int canPaint(int arr[], int n, int k, int maxTime) {
    int painters = 1;
    int time = 0;

    for (int i = 0; i < n; i++) {
        // If single board exceeds maxTime → impossible
        if (arr[i] > maxTime)
            return 0;

        if (time + arr[i] <= maxTime) {
            time += arr[i];
        } else {
            painters++;
            time = arr[i];
        }
    }

    return painters <= k;
}

int main() {
    int n, k;

    // Input
    printf("Enter number of boards and painters: ");
    scanf("%d %d", &n, &k);

    int arr[n];
    printf("Enter board lengths:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Binary Search range
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        right += arr[i];        // total length
        if (arr[i] > left)
            left = arr[i];     // max single board
    }

    int ans = right;

    // Binary Search
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canPaint(arr, n, k, mid)) {
            ans = mid;          // possible answer
            right = mid - 1;    // try smaller time
        } else {
            left = mid + 1;     // increase time
        }
    }

    // Output
    printf("Minimum time required = %d\n", ans);

    return 0;
}
