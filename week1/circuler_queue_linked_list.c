#include<stdio.h>
#include<stdlib.h>

// Node structure for the queue
struct node {
    int data;
    struct node* next;
};

// Global pointers to track the front and rear of the queue
struct node* front = NULL;
struct node* rear = NULL;

// Function to add an element to the queue
void enqueue(int x) {
    // Allocate memory for a new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if (rear == NULL) {
        // Queue is empty: new node is both front and rear
        front = rear = newnode;
        rear->next = front;  // Make it circular
    } else {
        // Insert at the end and update rear
        rear->next = newnode;
        rear = newnode;
        rear->next = front;  // Maintain circular link
    }
}

// Function to remove an element from the front of the queue
void dequeue() {
    struct node* temp;

    // Check for empty queue
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;

    // If there's only one node
    if (front == rear) {
        front = rear = NULL;
    } else {
        // Move front to next node and update rear's link
        front = front->next;
        rear->next = front;
    }

    // Free the removed node
    free(temp);
}

// Function to view the element at the front
void peek() {
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front: %d\n", front->data);
    }
}

// Function to display all elements of the queue
void display() {
    struct node* temp = front;

    // Check for empty queue
    if (front == NULL && rear == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    // Traverse from front to rear (circularly)
    printf("Queue: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != front);  // Loop ends when we circle back to front

    printf("\n");
}

// Main function to test queue operations
int main() {
    dequeue();           // Try to dequeue from empty queue (edge case)
    enqueue(20);         // Enqueue 20
    enqueue(30);         // Enqueue 30
    display();           // Should print: Queue: 20 30
    peek();              // Should print: Front: 20
    dequeue();           // Remove 20
    enqueue(40);         // Enqueue 40
    enqueue(50);         // Enqueue 50
    enqueue(60);         // Enqueue 60
    display();           // Should print: Queue: 30 40 50 60
    peek();              // Should print: Front: 30
    return 0;
}

