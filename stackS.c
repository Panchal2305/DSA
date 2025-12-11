#include <stdio.h>

#define SIZE 100

// ---------- STACK ----------
int stack[SIZE];
int top = -1;

void push(int x) { stack[++top] = x; }
int pop() { return (top == -1) ? -1 : stack[top--]; }
int peek() { return (top == -1) ? -1 : stack[top]; }
int isEmpty() { return top == -1; }

// ---------- QUEUE ----------
int queue[SIZE];
int front = -1, rear = -1;

void enqueue(int x) {
    if (front == -1) front = 0;
    queue[++rear] = x;
}

void printQueue() {
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

// ---------- NEXT SMALLER ELEMENT ----------
void nextSmaller(int arr[], int n) {
    for (int i = n - 1; i >= 0; i--) {

        // Pop larger or equal elements
        while (!isEmpty() && peek() >= arr[i])
            pop();

        // If stack empty → no smaller element
        int nse = isEmpty() ? -1 : peek();

        enqueue(nse);   // store answer in queue

        push(arr[i]);   // push current element
    }
}

int main() {
    int arr[SIZE], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    nextSmaller(arr, n);

    printf("\nNext Smaller Elements:\n");
    printQueue();

    return 0;
}
