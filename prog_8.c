#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Function Prototypes ---
void bubbleSort(int arr[], int n, long *comparisons, long *swaps);
void selectionSort(int arr[], int n, long *comparisons, long *swaps);
void insertionSort(int arr[], int n, long *comparisons, long *swaps);
void mergeSort(int arr[], int l, int r, long *comparisons, long *swaps);
void merge(int arr[], int l, int m, int r, long *comparisons, long *swaps);
void printArray(int arr[], int n);
void generateRandomArray(int arr[], int n);

// --- Main Function ---
int main() {
    int n, choice;
    long comparisons = 0;
    long swaps = 0;

    printf("--- Sorting Algorithm Performance Analyzer ---\n\n");
    
    // Get array size
    printf("Enter the number of integers (N): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    // Allocate memory and generate random array
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    generateRandomArray(arr, n);

    printf("\nGenerated Array (Before Sorting):\n");
    printArray(arr, n);
    printf("\n");

    // Menu
    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    printf("\n");

    // Execute Sorting
    switch (choice) {
        case 1:
            printf("Running Bubble Sort...\n");
            bubbleSort(arr, n, &comparisons, &swaps);
            break;
        case 2:
            printf("Running Selection Sort...\n");
            selectionSort(arr, n, &comparisons, &swaps);
            break;
        case 3:
            printf("Running Insertion Sort...\n");
            insertionSort(arr, n, &comparisons, &swaps);
            break;
        case 4:
            printf("Running Merge Sort...\n");
            mergeSort(arr, 0, n - 1, &comparisons, &swaps);
            break;
        default:
            printf("Invalid choice.\n");
            free(arr);
            return 1;
    }

    // Results
    printf("\nSorted Array:\n");
    printArray(arr, n);
    
    printf("\n--- Performance Metrics ---\n");
    printf("Total Comparisons: %ld\n", comparisons);
    printf("Total Swaps (or Array Writes): %ld\n", swaps);

    free(arr);
    return 0;
}

// --- Function Implementations ---

void generateRandomArray(int arr[], int n) {
    srand(time(NULL)); // Seed random number generator
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1; // Range [1, 1000]
    }
}

void printArray(int arr[], int n) {
    // Print first 50 elements if array is large for readability
    int limit = (n > 50) ? 50 : n;
    for (int i = 0; i < limit; i++) {
        printf("%d ", arr[i]);
    }
    if (n > 50) {
        printf("... (and %d more)", n - 50);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n, long *comparisons, long *swaps) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                // Swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

void selectionSort(int arr[], int n, long *comparisons, long *swaps) {
    int i, j, min_idx, temp;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*comparisons)++;
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i) {
            // Swap
            temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
            (*swaps)++;
        }
    }
}

void insertionSort(int arr[], int n, long *comparisons, long *swaps) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        (*comparisons)++; // Comparison for the first iteration of the while loop
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            (*swaps)++; // Shifting element
            j = j - 1;
            if (j >= 0) (*comparisons)++; // Comparison for subsequent iterations
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r, long *comparisons, long *swaps) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copy data to temp arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*swaps)++; // Counting array write as a "move" or swap
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        (*swaps)++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        (*swaps)++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r, long *comparisons, long *swaps) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m, comparisons, swaps);
        mergeSort(arr, m + 1, r, comparisons, swaps);
        merge(arr, l, m, r, comparisons, swaps);
    }
}
