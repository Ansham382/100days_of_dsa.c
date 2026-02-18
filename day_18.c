/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/
#include <stdio.h>

int main()
{
    int n, k, i, j, temp;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);

    // Rotate one by one k times
    for(i = 0; i < k; i++)
    {
        temp = arr[n-1];   // store last element

        for(j = n-1; j > 0; j--)
        {
            arr[j] = arr[j-1];
        }

        arr[0] = temp;     // put last element at first
    }

    printf("Rotated array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
