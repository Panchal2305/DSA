#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse the linked list
void reverseList(struct Node** head) {
    struct Node *prev = NULL, *current = *head, *next = NULL;

    while (current != NULL) {
        next = current->next;  // store next node
        current->next = prev;  // reverse pointer
        prev = current;        // move prev forward
        current = next;        // move current forward
    }
    *head = prev; // new head
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Insert sample values
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 10);

    printf("Original Linked List:\n");
    printList(head);

    reverseList(&head);

    printf("Reversed Linked List:\n");
    printList(head);

    return 0;
}
