/*Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1
*/
#include <stdio.h>

int main()
{
    int n;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(int i = 0; i < n; i++)
    {
        int count = 1;

        // Skip if already counted
        int alreadyCounted = 0;
        for(int k = 0; k < i; k++)
        {
            if(arr[i] == arr[k])
            {
                alreadyCounted = 1;
                break;
            }
        }

        if(alreadyCounted == 1)
            continue;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
            }
        }

        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
