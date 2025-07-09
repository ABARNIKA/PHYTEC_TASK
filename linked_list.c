#include <stdio.h>
#include <stdlib.h>

// Node structure for the singly linked list
struct node {
    int data;
    struct node* next;
};

// Global head pointer to the start of the list
struct node* head = NULL;

// Function to insert a node at the front of the list
void insertion_front() {
    // Allocate memory for a new node
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Take input from the user for node data
    printf("Enter the node: ");
    scanf("%d", &newnode->data);

    // Point new node's next to current head
    newnode->next = head;

    // Make new node the new head
    head = newnode;
}

// Function to display all nodes in the linked list
void display() {
    struct node* temp = head;

    // Check if list is empty
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    // Traverse and print the list
    while (temp != NULL) {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");  // End of list
}

// Function to delete the last node of the list
void delete_end()
{
    // Check if list is empty
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }

    // If only one node is present
    if (head->next == NULL) {
        free(head);   // Free the only node
        head = NULL;
        return;
    }

    // Traverse to the second last node
    struct node* temp = head;
    struct node* prenode = NULL;
    while (temp->next != NULL) {
        prenode = temp;
        temp = temp->next;
    }

    // Unlink and free the last node
    prenode->next = NULL;
    free(temp);
}

/*
// Optional: Function to delete the first node (beginning)
void delete_beg() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }

    struct node* temp = head;
    head = head->next;
    free(temp);
}
*/

int main() {
    // Insert 4 nodes at the front
    insertion_front();  // 1st node
    insertion_front();  // 2nd node
    insertion_front();  // 3rd node
    insertion_front();  // 4th node

    // Display the list after insertion
    display();

    // Delete the last node from the list
    delete_end();

    // Display the list after deletion from end
    printf("\nLinked List after deleting from end:\n");
    display();

    return 0;
}

