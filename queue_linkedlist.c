#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the queue
struct Node {
    int data;                // Holds the value
    struct Node* next;       // Points to the next node in the queue
};

// Global pointers to track front and rear of the queue
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to insert an element into the queue
void enqueue(int value) {
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;      // Set data
    newNode->next = NULL;       // Set next pointer to NULL

    // If queue is empty, front and rear are the same
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        // Otherwise, add at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted: %d\n", value);
}

// Function to remove an element from the front of the queue
void dequeue() {
    // Check if queue is empty
    if (front == NULL) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    // Store front node temporarily and move front to next
    struct Node* temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    // If front becomes NULL, queue is now empty
    if (front == NULL) {
        rear = NULL;
    }

    // Free memory of dequeued node
    free(temp);
}

// Function to display all elements in the queue
void display() {
    struct Node* temp = front;

    // Check if queue is empty
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    // Print each element from front to rear
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test queue operations
int main() {
    // Test dequeue on empty queue
    dequeue();

    // Insert elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();   // Expected: 10 20 30

    // Remove one element and display again
    dequeue();   // Removes 10
    display();   // Expected: 20 30

    // Insert another element
    enqueue(40);
    display();   // Expected: 20 30 40

    // Remove another element
    dequeue();   // Removes 20
    display();   // Expected: 30 40

    return 0;
}

