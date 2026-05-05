/*Problem Statement
Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

Books must be allocated in contiguous order.

Input Format
n m
n space-separated integers representing pages in books

Output Format
Print the minimum possible value of the maximum pages assigned to any student.

Sample Input
4 2
12 34 67 90

Sample Output
113

Explanation
One optimal allocation is:
Student 1: 12 + 34 + 67 = 113
Student 2: 90
Maximum pages = 113 (minimum possible).*/

#include <stdio.h>

// Check if allocation is possible with maxPages limit
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        // If a single book has more pages than maxPages → impossible
        if (arr[i] > maxPages)
            return 0;

        if (pages + arr[i] <= maxPages) {
            pages += arr[i];
        } else {
            students++;
            pages = arr[i];
        }
    }

    return students <= m;
}

int main() {
    int n, m;

    // Input
    printf("Enter number of books and students: ");
    scanf("%d %d", &n, &m);

    int arr[n];
    printf("Enter pages of books:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Binary Search range
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        right += arr[i];    // total pages
        if (arr[i] > left)
            left = arr[i];  // max single book
    }

    int ans = right;

    // Binary Search
    while (left <= right) {
        int mid = (left + right) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;          // possible answer
            right = mid - 1;    // try smaller max
        } else {
            left = mid + 1;     // increase limit
        }
    }

    // Output
    printf("Minimum maximum pages = %d\n", ans);

    return 0;
}
