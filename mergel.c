#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end of linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Merge two sorted linked lists
struct Node* mergeLists(struct Node* l1, struct Node* l2) {
    // If one list is empty
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct Node* result = NULL;

    // Choose the smaller value first
    if (l1->data <= l2->data) {
        result = l1;
        result->next = mergeLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeLists(l1, l2->next);
    }
    return result;
}

// Print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *list1 = NULL, *list2 = NULL;
    int n1, n2, value;

    // Input first sorted list
    printf("Enter number of nodes in List 1: ");
    scanf("%d", &n1);
    printf("Enter %d sorted values:\n", n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    // Input second sorted list
    printf("Enter number of nodes in List 2: ");
    scanf("%d", &n2);
    printf("Enter %d sorted values:\n", n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    printf("\nList 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    // Merge
    struct Node* merged = mergeLists(list1, list2);

    printf("\nMerged Sorted List: ");
    printList(merged);

    return 0;
}
