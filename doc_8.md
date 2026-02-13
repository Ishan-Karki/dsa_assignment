# Documentation for Sorting Algorithm Performance Analyzer (Question 8)

## Data Structures

The program works with a dynamically allocated array of integers:

```c
int *arr = (int*)malloc(n * sizeof(int));
```

- `n`: The number of elements, provided by the user at runtime.
- `arr`: Stores the random integers generated in the range [1, 1000].

## Functions

1.  **`void generateRandomArray(int arr[], int n)`**: Populates the array with random numbers. Uses `srand(time(NULL))` to ensure different sequences on each run.
2.  **`void printArray(int arr[], int n)`**: Helper to display the array. It truncates the output for large `N` to keep the console readable.
3.  **Sorting Functions**:
    - Each sorting function takes `long *comparisons` and `long *swaps` pointers to track performance metrics.
    - **`void bubbleSort(...)`**: Implements the standard Bubble Sort algorithm. Counts a comparison for every inner loop check and a swap for every out-of-order pair.
    - **`void selectionSort(...)`**: Implements Selection Sort. Finds the minimum element in the unsorted portion and swaps it with the first unsorted element.
    - **`void insertionSort(...)`**: Implements Insertion Sort. Shifts elements to make space for the key element. Counts shifts as swaps/data moves.
    - **`void mergeSort(...)`** and **`merge(...)`**: Implement Merge Sort (recursive). Counts comparisons during the merge phase and array writes (moves) as swaps.

## Main Function Organization

The `main()` function:
1.  Prompts the user for the number of elements `N`.
2.  Generates the random array and prints it (or a preview).
3.  Displays a menu for the user to select a sorting algorithm (1-4).
4.  Executes the selected algorithm, passing pointers to the counter variables.
5.  Prints the sorted array (or preview).
6.  Displays the total number of comparisons and swaps/moves performed.

## Sample Output

```text
--- Sorting Algorithm Performance Analyzer ---

Enter the number of integers (N): 50

Generated Array (Before Sorting):
843 125 932 45 10 78 ... (and 0 more)

Choose a sorting algorithm:
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
Enter your choice (1-4): 1

Running Bubble Sort...

Sorted Array:
10 45 78 125 843 ... (and 0 more)

--- Performance Metrics ---
Total Comparisons: 1225
Total Swaps (or Array Writes): 650
```
