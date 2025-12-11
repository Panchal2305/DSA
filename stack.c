#include <stdio.h>
#include <stdlib.h>

int *stack;      // dynamic array
int top = -1;    // top pointer
int capacity = 2; // initial size

// Function to resize the stack
void resize() {
    capacity *= 2;
    stack = realloc(stack, capacity * sizeof(int));
    printf("Stack resized! New capacity = %d\n", capacity);
}

// Push function
void push(int value) {
    if (top == capacity - 1) {
        resize();
    }
    stack[++top] = value;
    printf("%d pushed\n", value);
}

// Pop function
void pop() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("%d popped\n", stack[top--]);
    }
}

// Display function
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    stack = malloc(capacity * sizeof(int)); // initial memory

    int choice, value;
    while (1) {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                display();
                break;

            case 4:
                free(stack);
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
