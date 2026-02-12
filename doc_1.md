# Documentation for Balanced Parentheses Checker (Question 1)

## Data Structures

The program uses a **Stack** data structure to keep track of opening parentheses. It is implemented using a structure:

```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;
```

- `items`: An array of characters to store the stack elements.
- `top`: An integer representing the index of the top element in the stack.

## Functions

1.  **`void initStack(Stack *s)`**: Initializes the stack by setting `top` to -1.
2.  **`int isFull(Stack *s)`**: Checks if the stack has reached its maximum capacity (`MAX_SIZE - 1`). Returns 1 if full, 0 otherwise.
3.  **`int isEmpty(Stack *s)`**: Checks if the stack is empty (`top` is -1). Returns 1 if empty, 0 otherwise.
4.  **`void push(Stack *s, char value)`**: Adds a character to the top of the stack. Prints an error and exits if the stack is full.
5.  **`char pop(Stack *s)`**: Removes and returns the top character from the stack. Prints an error and exits if the stack is empty.
6.  **`int isMatchingPair(char character1, char character2)`**: Checks if two characters form a matching pair of parentheses (e.g., `(` and `)`, `{` and `}`). Returns 1 if they match, 0 otherwise.
7.  **`int checkBalanced(char *expression)`**: The core logic function. It traverses the expression string:
    - If an opening bracket is found, it is pushed onto the stack.
    - If a closing bracket is found, it checks if the stack is empty (unbalanced) or if the popped element matches the closing bracket.
    - Finally, it checks if the stack is empty to ensure all opening brackets were closed.
    - Returns 1 if balanced, 0 otherwise.

## Main Function Organization

The `main()` function serves as the driver for the program:

1.  It defines an array of test expressions as specified in the problem statement.
2.  It iterates through each expression in the array.
3.  For each expression, it calls `checkBalanced()`.
4.  Based on the return value, it prints "Balanced" or "Not Balanced".

## Sample Output

```text
--- Balanced Parentheses Checker ---

Expression 1: a + (b - c) * (d
Result: Not Balanced
------------------------------------
Expression 2: m + [a - b * (c + d * {m)]
Result: Not Balanced
------------------------------------
Expression 3: a + (b - c)
Result: Balanced
------------------------------------
```
