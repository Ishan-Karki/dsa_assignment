#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

// --- Stack Structure ---
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// --- Function Prototypes ---
void initStack(Stack *s);
int isFull(Stack *s);
int isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack *s);
int peek(Stack *s);
int precedence(char op);
int isOperator(char ch);
void infixToPostfix(char *infix, char *postfix);
int evaluatePostfix(char *postfix);

// --- Main Function ---
int main() {
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];
    
    // Test case 1
    strcpy(infix, "3+4*2/(1-5)^2");
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
    printf("\n");

    // Test case 2 (Standard Example)
    strcpy(infix, "((8+2)*3)-4"); // ((10)*3)-4 = 30-4 = 26
    printf("Infix Expression: %s\n", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfix));

    return 0;
}

// --- Stack Operations ---
void initStack(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int peek(Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
}

// --- Helper Functions ---
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// --- Infix to Postfix Conversion ---
void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0, j = 0;
    
    while (infix[i] != '\0') {
        char token = infix[i];
        
        // Use alphanumeric characters (digits/letters) as operands
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        else if (token == '(') {
            push(&s, token);
        }
        else if (token == ')') {
            while (!isEmpty(&s) && peek(&s) != '(') {
                postfix[j++] = (char)pop(&s);
            }
            if (!isEmpty(&s) && peek(&s) != '(') {
                printf("Invalid Expression\n"); // Mismatched parentheses
                return;
            } else {
                pop(&s); // Pop '('
            }
        }
        else if (isOperator(token)) {
            while (!isEmpty(&s) && precedence((char)peek(&s)) >= precedence(token)) {
                // Determine associativity: '^' is right-associative
                if (token == '^' && (char)peek(&s) == '^') {
                    break; 
                }
                postfix[j++] = (char)pop(&s);
            }
            push(&s, token);
        }
        i++;
    }
    
    while (!isEmpty(&s)) {
        postfix[j++] = (char)pop(&s);
    }
    postfix[j] = '\0';
}

// --- Postfix Evaluation ---
int evaluatePostfix(char *postfix) {
    Stack s;
    initStack(&s);
    int i = 0;
    
    while (postfix[i] != '\0') {
        char token = postfix[i];
        
        if (isdigit(token)) {
            push(&s, token - '0');
        }
        else if (isOperator(token)) {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (token) {
                case '+': push(&s, val1 + val2); break;
                case '-': push(&s, val1 - val2); break;
                case '*': push(&s, val1 * val2); break;
                case '/': push(&s, val1 / val2); break;
                case '^': push(&s, (int)pow(val1, val2)); break;
            }
        }
        i++;
    }
    return pop(&s);
}
