#include <stdio.h>
#include <stdlib.h>

// Define a node for the queue
struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

// Function to add a number to the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Inserted: %d\n", value);
}

// Function to delete the first number inserted (from the front)
void dequeue() {
    if (front == NULL) {
        printf("Queue is empty. Cannot delete.\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted: %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;  // Queue is now empty
    }

    free(temp);
}

// Function to display the queue
void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the operations
int main() {
	dequeue();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    dequeue();
    display();

    return 0;
}
