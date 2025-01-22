#include <stdio.h>
#include <stdlib.h>

// Swap utility function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify function for Max Heap
void minHeapify(int arr[], int n, int i) {
    int lowest = i;        // Initialize largest as root
    int left = 2 * i + 1;   // Left child
    int right = 2 * i + 2;  // Right child

    if (left < n && arr[left] < arr[lowest]) {
        lowest = left;
    }

    if (right < n && arr[right] < arr[lowest]) {
        lowest = right;
    }

    if (lowest != i) {
        swap(&arr[i], &arr[lowest]);
        minHeapify(arr, n, lowest);
    }
}

// Extract the maximum element from the Max Heap
int extractMin(int arr[], int *n) {
    if (*n <= 0) {
        return -1; // Heap is empty
    }

    int root = arr[0];       // Get the maximum element
    arr[0] = arr[*n - 1];    // Replace root with the last element
    (*n)--;                  // Reduce heap size
    minHeapify(arr, *n, 0);  // Heapify the root

    return root;
}

// Heapsort using Max Heap
void heapSortMin(int arr[], int n) {
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);  // Move current root to end
        minHeapify(arr, i, 0);   // Heapify the reduced heap
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function for testing Max Heap
int main() {
    int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array:\n");
    printArray(arr, n);

    heapSortMin(arr, n);

    printf("Sorted Array (Min Heap):\n");
    printArray(arr, n);

    return 0;
}
