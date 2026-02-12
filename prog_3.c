#include <stdio.h>
#include <stdlib.h>

// --- Linked List Node Structure ---
struct Node {
    int data;
    struct Node *next;
};

// --- Function Prototypes ---
struct Node* createNode(int data);
void insertAtEnd(struct Node **head, int data);
void traverseNormal(struct Node *head);
void traverseReverse(struct Node *head);

// --- Main Function ---
int main() {
    struct Node *head = NULL;

    printf("--- Reverse Traversal of Linked List ---\n\n");

    // Creating the linked list: 10 -> 20 -> 30 -> 40 -> 50
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);

    printf("Normal Order: ");
    traverseNormal(head);
    printf("\n");

    printf("Reverse Order: ");
    traverseReverse(head);
    printf("\n");

    return 0;
}

// --- Function Implementations ---

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node **head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = createNode(data);
}

void traverseNormal(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Recursive function to print the linked list in reverse order
void traverseReverse(struct Node *head) {
    if (head == NULL) {
        return;
    }
    // Recursive call first
    traverseReverse(head->next);
    // Print after recursive implementation returns
    printf("%d ", head->data);
}
