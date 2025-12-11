#include <stdio.h>
#include <stdlib.h>

int *queue;         // dynamic array
int front = -1;
int rear = -1;
int capacity = 2;   // initial queue size

// Resize the queue when full
void resize() {
    capacity *= 2;
    queue = realloc(queue, capacity * sizeof(int));
    printf("Queue resized! New capacity = %d\n", capacity);
}

// Enqueue operation
void enqueue(int value) {
    // Queue is full
    if (rear == capacity - 1) {
        resize();
    }

    if (front == -1) front = 0;  // first element

    queue[++rear] = value;
    printf("%d enqueued\n", value);
}

// Dequeue operation
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    printf("%d dequeued\n", queue[front++]);

    // Reset when all elements removed
    if (front > rear) {
        front = rear = -1;
    }
}

// Display queue
void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function
int main() {
    queue = malloc(capacity * sizeof(int));  // initial memory

    int choice, value;

    while (1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                free(queue);
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
