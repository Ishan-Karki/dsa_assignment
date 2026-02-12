#include <stdio.h>
#include <stdlib.h>

// --- Doubly Linked List Node Structure ---
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// --- Function Prototypes ---
struct Node* createNode(int data);
void insertAtHead(struct Node **head_ref, int data);
void insertAfter(struct Node* prev_node, int new_data);
void deleteNode(struct Node** head_ref, struct Node* del);
void printList(struct Node *node);

// --- Main Function ---
int main() {
    struct Node* head = NULL;
    
    printf("--- Doubly Linked List Operations ---\n\n");

    // Creating initial list: 2 -> 4 -> 6
    insertAtHead(&head, 6);
    insertAtHead(&head, 4);
    insertAtHead(&head, 2);
    
    printf("Initial List: ");
    printList(head);
    
    // Demonstrate insertAfter
    // Let's insert 5 after the second node (which is 4)
    // To do this strictly by "after given node", we need a pointer to the node "4".
    struct Node *temp = head->next; // points to 4
    printf("Inserting 5 after node with data %d...\n", temp->data);
    insertAfter(temp, 5);
    
    printf("List after insertion: ");
    printList(head); // Should be 2 -> 4 -> 5 -> 6
    
    // Demonstrate deleteNode
    // Let's delete the node with data 5 (which is temp->next now)
    struct Node *nodeToDelete = temp->next;
    printf("Deleting node with data %d...\n", nodeToDelete->data);
    deleteNode(&head, nodeToDelete);
    
    printf("List after deletion: ");
    printList(head); // Should be 2 -> 4 -> 6

    return 0;
}

// --- Function Implementations ---

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Helper to build the list
void insertAtHead(struct Node **head_ref, int data) {
    struct Node *newNode = createNode(data);
    
    newNode->next = (*head_ref);
    newNode->prev = NULL;
    
    if ((*head_ref) != NULL) {
        (*head_ref)->prev = newNode;
    }
    (*head_ref) = newNode;
}

/* Given a node as prev_node, insert a new node after the given prev_node */
void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }
    
    struct Node* new_node = createNode(new_data);
    
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;
    
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}

/* Deletes a node from the doubly linked list */
void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) {
        return;
    }
    
    // If node to be deleted is head node
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    
    // Change next only if node to be deleted is NOT the last node
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }
    
    // Change prev only if node to be deleted is NOT the first node
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }
    
    free(del);
}

void printList(struct Node *node) {
    struct Node *last;
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
    printf("\n");
}
