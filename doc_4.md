# Documentation for Doubly Linked List Operations (Question 4)

## Data Structures

The program uses a **Doubly Linked List** node structure, which contains pointers to both the next and previous nodes:

```c
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};
```

- `data`: Stores the integer value.
- `prev`: Pointer to the previous node in the list.
- `next`: Pointer to the next node in the list.

## Functions

1.  **`struct Node* createNode(int data)`**: Allocates memory for a new node and initializes its pointers to NULL.
2.  **`void insertAtHead(struct Node **head_ref, int data)`**: Adds a new node at the beginning of the list. Updates the `prev` pointer of the old head if it exists.
3.  **`void insertAfter(struct Node* prev_node, int new_data)`**: Inserts a new node **after** a given node.
    - Updates 4 pointers:
        1.  `new_node->next` points to `prev_node->next`.
        2.  `prev_node->next` points to `new_node`.
        3.  `new_node->prev` points to `prev_node`.
        4.  If `new_node->next` is not NULL, `new_node->next->prev` points to `new_node`.
4.  **`void deleteNode(struct Node** head_ref, struct Node* del)`**: Deletes a specific node from the list.
    - Handles edge cases: head node deletion, tail node deletion.
    - Updates `next` of the previous node and `prev` of the next node to bypass the deleted node.
    - Frees the memory of the deleted node.
5.  **`void printList(struct Node *node)`**: Traverses and prints the list content.

## Main Function Organization

The `main()` function:
1.  Creates an initial doubly linked list with values `2 -> 4 -> 6`.
2.  Demonstrates `insertAfter` by inserting `5` after the node containing `4`.
3.  Demonstrates `deleteNode` by removing the newly inserted node `5`.
4.  Prints the list state at each step to verify correctness.

## Sample Output

```text
--- Doubly Linked List Operations ---

Initial List: 2 4 6 
Inserting 5 after node with data 4...
List after insertion: 2 4 5 6 
Deleting node with data 5...
List after deletion: 2 4 6 
```
