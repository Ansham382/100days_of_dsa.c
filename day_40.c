/*Implement Heap Sort using a Max Heap to sort an array in ascending order. First build a max heap, 
then repeatedly extract the maximum element and place it at the end of the array.*/
#include <stdio.h>

// function to swap two numbers
void swap(int *a, int *b) {
    int temp = *a;   // store first value
    *a = *b;         // copy second into first
    *b = temp;       // put temp into second
}

// function to make max heap
void heapify(int arr[], int n, int i) {
    int largest = i;        // assume root is largest
    int left = 2 * i + 1;   // left child index
    int right = 2 * i + 2;  // right child index

    // check if left child is bigger
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // check if right child is bigger
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // if root is not largest then swap
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // call heapify again for affected part
        heapify(arr, n, largest);
    }
}

// heap sort function
void heapSort(int arr[], int n) {

    // step 1: build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // step 2: take largest element one by one
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);   // move largest to end

        // heapify remaining array
        heapify(arr, i, 0);
    }
}

// function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

// main function
int main() {
    int n;

    // taking size from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // taking array elements
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // printing original array
    printf("Original array:\n");
    printArray(arr, n);

    // calling heap sort
    heapSort(arr, n);

    // printing sorted array
    printf("\nSorted array:\n");
    printArray(arr, n);

    return 0;
}
  
