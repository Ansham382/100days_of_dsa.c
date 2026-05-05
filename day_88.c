/*Problem Statement
Given n stalls located at different positions along a straight line and k cows, place the cows in the stalls such that the minimum distance between any two cows is maximized.

This is an optimization problem where binary search on the answer is required.

Input Format
n k
n space-separated integers representing stall positions

Output Format
Print the maximum possible minimum distance between any two cows.

Sample Input
5 3
1 2 8 4 9

Sample Output
3

Explanation
Cows can be placed at positions 1, 4, and 8. The minimum distance between any two cows is 3, which is the maximum possible.*/

#include <stdio.h>

// Function to sort array (simple bubble sort)
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Check if cows can be placed with minimum distance 'dist'
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;        // first cow placed at first stall
    int lastPos = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - lastPos >= dist) {
            count++;
            lastPos = arr[i];
        }
        if(count >= k)
            return 1;
    }
    return 0;
}

int main() {
    int n, k;

    // Input
    printf("Enter number of stalls and cows: ");
    scanf("%d %d", &n, &k);

    int arr[n];
    printf("Enter stall positions:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 1: Sort
    sort(arr, n);

    // Binary Search on answer
    int left = 1;
    int right = arr[n - 1] - arr[0];
    int ans = 0;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(canPlace(arr, n, k, mid)) {
            ans = mid;          // possible answer
            left = mid + 1;     // try bigger distance
        } else {
            right = mid - 1;    // try smaller distance
        }
    }

    // Output
    printf("Maximum minimum distance = %d\n", ans);

    return 0;
}
