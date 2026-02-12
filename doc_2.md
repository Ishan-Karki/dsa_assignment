# Documentation for Infix to Postfix Conversion and Evaluation (Question 2)

## Data Structures

The program uses a **Stack** data structure, similar to Question 1, but adapted to store `int` values. This allows it to store characters (as integers) for the conversion phase and integer operands for the evaluation phase.

```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;
```

## Functions

1.  **Stack Operations**: `initStack`, `isFull`, `isEmpty`, `push`, `pop`, `peek` (standard stack operations).
2.  **`int precedence(char op)`**: Returns the precedence level of an operator:
    - `^`: 3
    - `*`, `/`: 2
    - `+`, `-`: 1
    - Others: 0
3.  **`int isOperator(char ch)`**: Helper to check if a character is an operator.
4.  **`void infixToPostfix(char *infix, char *postfix)`**: Converts the infix string to postfix notation.
    - Uses a stack to hold operators.
    - Appends operands directly to the `postfix` string.
    - Respects operator precedence and associativity (e.g., `^` is right-associative).
    - Handles parentheses `(` and `)`.
5.  **`int evaluatePostfix(char *postfix)`**: Evaluates the postfix expression.
    - Uses a stack to hold operands.
    - Be aware: It performs integer arithmetic (e.g., `8/16` is `0`).
    - Uses `pow()` for exponentiation.

## Main Function Organization

The `main()` function:
1.  Defines sample infix expressions (e.g., `3+4*2/(1-5)^2`).
2.  Calls `infixToPostfix()` to convert the expression and prints it.
3.  Calls `evaluatePostfix()` to compute the result and prints it.

## Sample Output

```text
Infix Expression: 3+4*2/(1-5)^2
Postfix Expression: 342*15-2^/+
Evaluation Result: 3

Infix Expression: ((8+2)*3)-4
Postfix Expression: 82+3*4-
Evaluation Result: 26
```