#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

// Stack
int stack[SIZE], top = -1;
void push(int x) { stack[++top] = x; }
int pop() { return (top == -1) ? -1 : stack[top--]; }
int peek() { return (top == -1) ? -1 : stack[top]; }
int isEmpty() { return top == -1; }

// Queue (to print results)
int queue[SIZE], front = -1, rear = -1;
void enqueue(int x) {
    if (front == -1) front = 0;
    queue[++rear] = x;
}
void printQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// Next Greater Element function
void nextGreater(int arr[], int n) {
    // Process elements from right to left
    for (int i = n - 1; i >= 0; i--) {

        // Pop smaller elements
        while (!isEmpty() && peek() <= arr[i])
            pop();

        // If empty → no greater element
        int nge = isEmpty() ? -1 : peek();

        enqueue(nge);   // store result in queue

        push(arr[i]);  // push current element
    }
}

int main() {
    int arr[SIZE], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    nextGreater(arr, n);

    printf("\nNext Greater Elements:\n");
    printQueue();  // print using queue

    return 0;
}

