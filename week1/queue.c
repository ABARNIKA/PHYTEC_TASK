#include<stdio.h>
#include<stdlib.h>

#define n 25  // Define the maximum size of the queue

int queue[n];        // Array to store queue elements
int front = -1;      // Front pointer (index of the first element)
int rear = -1;       // Rear pointer (index of the last element)

// Function to add an element to the queue
void enqueue(int x) {
    if (rear == n - 1) {  // Check if the queue is full
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1) {  // If queue is initially empty
        front = rear = 0;
        queue[rear] = x;
    }
    else {
        rear++;           // Move rear pointer and add element
        queue[rear] = x;
    }
}

// Function to remove an element from the queue
void dequeue() {
    if (front == -1 && rear == -1) {  // If queue is empty
        printf("Queue is empty\n");
    }
    else if (front == rear) {  // If only one element is present
        front = rear = -1;     // Reset queue
    }
    else {
        printf("\nDeleted Queue: %d\n", queue[front]);  // Print deleted element
        front++;  // Move front pointer to next element
    }
}

// Function to display all elements in the queue
void display() {
    if (front == -1 && rear == -1) {  // If queue is empty
        printf("Queue is empty\n");
    }
    else {
        printf("Queue contains: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);  // Print elements from front to rear
        }
        printf("\n");
    }
}

// Function to display the front (peek) element of the queue
void peek() {
    if (front == -1 && rear == -1) {  // If queue is empty
        printf("Queue is empty\n");
    }
    else {
        printf("\nThe peek element is: %d\n", queue[front]);  // Print the front element
    }
}

int main() {
    // Enqueue a few elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    // Display the queue
    display();

    // Dequeue one element
    dequeue();

    // Display the queue again
    display();

    // Peek at the front element
    peek();

    // Dequeue another element
    dequeue();

    return 0;
}

