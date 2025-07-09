#include<stdio.h>
#include<stdlib.h>

#define n 25  // Define maximum size of the circular queue

int queue[n];      // Array to hold the elements of the queue
int front = -1;    // Index of the front element
int rear = -1;     // Index of the rear element

// Function to add an element to the queue
void enqueue(int x){
    if(front == -1 && rear == -1)  // If the queue is empty
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else if(((rear + 1) % n) == front)  // If the queue is full (next position is front)
    {
        printf("Queue is full\n");
    }
    else{
        rear = (rear + 1) % n;   // Move rear to next circular position
        queue[rear] = x;         // Add element at rear
    }
}

// Function to remove an element from the queue
void dequeue()
{
    if(front == -1 && rear == -1)  // Queue is empty
    {
        printf("Queue is empty\n");
    }
    else if(front == rear)  // Only one element in the queue
    {
        printf("deleted Queue: %d\n", queue[front]);
        front = rear = -1;  // Reset queue to empty
    }
    else
    {
        printf("\nDeleted Queue: %d\n", queue[front]);
        front = (front + 1) % n;  // Move front to next circular position
    }
}

// Function to display elements of the queue
void display()
{
    int i = front;
    if(front == -1 && rear == -1)  // Queue is empty
    {
        printf("Queue is empty\n");
    }
    else {
        printf("Queue contains: ");
        while(i != rear)  // Traverse from front to rear
        {
            printf("%d ", queue[i]);
            i = (i + 1) % n;
        }
        printf("%d\n", queue[rear]);  // Print the last element
    }
}

// Function to show the front element without deleting
void peek()
{
    if(front == -1 && rear == -1)  // Queue is empty
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("\nThe peek element is: %d\n", queue[front]);  // Display front element
    }
}

int main()
{
    // Enqueue a few elements
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    // Dequeue one element
    dequeue();

    // Display the current queue
    display();

    // Peek at the front element
    peek();

    // Add more elements and perform multiple dequeues
    enqueue(60);
    enqueue(70);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();  // These dequeues will eventually empty the queue
    dequeue();  // These might show "Queue is empty" if already empty
    dequeue();
    dequeue();

    return 0;
}

