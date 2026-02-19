/*Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int minSum = abs(arr[0] + arr[1]);
    int x = arr[0], y = arr[1];

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            int sum = arr[i] + arr[j];

            if(abs(sum) < minSum)
            {
                minSum = abs(sum);
                x = arr[i];
                y = arr[j];
            }
        }
    }

    printf("Pair whose sum is closest to zero: %d %d\n", x, y);

    return 0;
}
