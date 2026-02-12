#include <stdio.h>
#include <stdlib.h>

// --- Function Prototypes ---
void swap(int *a, int *b);
void heapifyMax(int arr[], int n, int i);
void buildMaxHeap(int arr[], int n);
void heapifyMin(int arr[], int n, int i);
void buildMinHeap(int arr[], int n);
void printArray(int arr[], int n);

// --- Main Function ---
int main() {
    int data[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(data) / sizeof(data[0]);

    // Create copies of the original array for heap operations
    int maxHeapArr[n];
    int minHeapArr[n];

    for (int i = 0; i < n; i++) {
        maxHeapArr[i] = data[i];
        minHeapArr[i] = data[i];
    }

    printf("--- Building Min and Max Heap ---\n\n");
    printf("Original Array: ");
    printArray(data, n);
    printf("\n");

    // Build Max Heap
    buildMaxHeap(maxHeapArr, n);
    printf("Max Heap: ");
    printArray(maxHeapArr, n);

    // Build Min Heap
    buildMinHeap(minHeapArr, n);
    printf("Min Heap: ");
    printArray(minHeapArr, n);

    return 0;
}

// --- Function Implementations ---

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// To heapify a subtree rooted with node i which is an index in arr[].
// n is size of heap
void heapifyMax(int arr[], int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left = 2*i + 1
    int right = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        heapifyMax(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapifyMax(arr, n, i);
    }
}

// To heapify a subtree rooted with node i which is an index in arr[].
void heapifyMin(int arr[], int n, int i) {
    int smallest = i; // Initialize smallest as root
    int left = 2 * i + 1; 
    int right = 2 * i + 2; 

    // If left child is smaller than root
    if (left < n && arr[left] < arr[smallest])
        smallest = left;

    // If right child is smaller than smallest so far
    if (right < n && arr[right] < arr[smallest])
        smallest = right;

    // If smallest is not root
    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);

        // Recursively heapify the affected sub-tree
        heapifyMin(arr, n, smallest);
    }
}

void buildMinHeap(int arr[], int n) {
    // Index of last non-leaf node
    int startIdx = (n / 2) - 1;

    // Perform reverse level order traversal from last non-leaf node and heapify each node
    for (int i = startIdx; i >= 0; i--) {
        heapifyMin(arr, n, i);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}
