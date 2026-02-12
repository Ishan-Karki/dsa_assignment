# Documentation for Reverse Linked List Traversal (Question 3)

## Data Structures

The program uses a **Singly Linked List** node structure:

```c
struct Node {
    int data;
    struct Node *next;
};
```

- `data`: Stores the integer value.
- `next`: Pointer to the next node in the list.

## Functions

1.  **`struct Node* createNode(int data)`**: Allocates memory for a new node and initializes it with the given data.
2.  **`void insertAtEnd(struct Node **head, int data)`**: Helper function to add nodes to the end of the list.
3.  **`void traverseNormal(struct Node *head)`**: Standard iterative traversal to print the list in order (for comparison).
4.  **`void traverseReverse(struct Node *head)`**: The core function for reverse traversal. It is implemented recursively:
    - Base case: If `head` is `NULL`, return.
    - Recursive step: Call `traverseReverse(head->next)` FIRST, before printing.
    - After the recursive call returns (unwinding the stack), print `head->data`.
    - This effectively prints the last element first, then the second-to-last, and so on.

## Main Function Organization

The `main()` function:
1.  Initializes an empty linked list.
2.  Inserts sample values (10, 20, 30, 40, 50).
3.  Calls `traverseNormal` to verify the list structure.
4.  Calls `traverseReverse` to demonstrate the reverse traversal algorithm.

## Sample Output

```text
--- Reverse Traversal of Linked List ---

Normal Order: 10 20 30 40 50 
Reverse Order: 50 40 30 20 10 
```
