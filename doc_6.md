# Documentation for Min and Max Heap Construction (Question 6)

## Data Structures

The program implements Heaps (Priority Queues) using an **Array** representation.
- For a node at index `i`:
    - Left Child: `2*i + 1`
    - Right Child: `2*i + 2`
    - Parent: `(i - 1) / 2`

## Functions

1.  **`void swap(int *a, int *b)`**: Helper function to swap two integers.
2.  **`void heapifyMax(int arr[], int n, int i)`**: Maintains the **Max-Heap** property for a subtree rooted at index `i`.
    - Compares the root with its left and right children.
    - If the root is not the largest, it swaps with the largest child.
    - Recursively calls itself on the affected subtree to propagate the change down.
3.  **`void buildMaxHeap(int arr[], int n)`**: Converts an arbitrary array into a Max-Heap.
    - Iterates from the last non-leaf node (`n/2 - 1`) up to `0`.
    - Calls `heapifyMax` for each node.
4.  **`void heapifyMin(int arr[], int n, int i)`**: Maintains the **Min-Heap** property for a subtree rooted at index `i`.
    - Similar logic to `heapifyMax`, but ensures the root is the smallest among itself and its children.
5.  **`void buildMinHeap(int arr[], int n)`**: Converts an arbitrary array into a Min-Heap.
    - Iterates from the last non-leaf node up to `0`.
    - Calls `heapifyMin` for each node.
6.  **`void printArray(int arr[], int n)`**: Helper to display the array contents.

## Main Function Organization

The `main()` function:
1.  Initializes an unsorted array: `{12, 11, 13, 5, 6, 7}`.
2.  Creates copies of this array for both heap operations.
3.  Calls `buildMaxHeap` on the first copy and prints the result.
4.  Calls `buildMinHeap` on the second copy and prints the result.

## Sample Output

```text
--- Building Min and Max Heap ---

Original Array: 12 11 13 5 6 7 

Max Heap: 13 11 12 5 6 7 
Min Heap: 5 6 7 11 12 13 
```
