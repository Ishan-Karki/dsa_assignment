#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// --- Function Prototypes ---

void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, char value);
char pop(Stack *s);
int isMatchingPair(char character1, char character2);
int checkBalanced(char *expression);

// --- Main Function ---

int main() {
    
    char *test_expressions[] = {
        "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };

    int num_tests = sizeof(test_expressions) / sizeof(test_expressions[0]);

    printf("--- Balanced Parentheses Checker ---\n\n");

    for (int i = 0; i < num_tests; i++) {
        printf("Expression %d: %s\n", i + 1, test_expressions[i]);
        
        if (checkBalanced(test_expressions[i])) {
            printf("Result: Balanced\n");
        } else {
            printf("Result: Not Balanced\n");
        }
        printf("------------------------------------\n");
    }

    return 0;
}

// --- Function Implementations ---

/* Initializes the stack by setting top to -1 */
void initStack(Stack *s) {
    s->top = -1;
}

/* Checks if the stack is full */
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

/* Checks if the stack is empty */
int isEmpty(Stack *s) {
    return s->top == -1;
}

/* Pushes a character onto the stack */
void push(Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

/* Pops a character from the stack */
char pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

/* Helper function to check if opening and closing brackets match */
int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')') return 1;
    if (character1 == '{' && character2 == '}') return 1;
    if (character1 == '[' && character2 == ']') return 1;
    return 0;
}

/* * Returns 1 if balanced, 0 if not balanced.
 */
int checkBalanced(char *expression) {
    Stack stack;
    initStack(&stack);
    int i = 0;

    while (expression[i]) {
        // If opening bracket, push to stack
        if (expression[i] == '{' || expression[i] == '(' || expression[i] == '[') {
            push(&stack, expression[i]);
        }
        // If closing bracket, check stack
        else if (expression[i] == '}' || expression[i] == ')' || expression[i] == ']') {
            if (isEmpty(&stack)) {
                return 0; // Found closing bracket with no opening bracket
            }
            char popped_char = pop(&stack);
            if (!isMatchingPair(popped_char, expression[i])) {
                return 0; // Mismatch found
            }
        }
        i++;
    }

    // If stack is empty at the end, parentheses are balanced
    return isEmpty(&stack) ? 1 : 0;
}