#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insertion_front() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the node: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}


void display() {
    struct node* temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf(" %d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void delete_end()
{
    if (head == NULL)
    {
        printf("List is already empty\n");
        return;
    }

    // If only one node is present
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node* temp = head;
    struct node* prenode = NULL;
    while (temp->next != NULL) {
        prenode = temp;
        temp = temp->next;
    }

    prenode->next = NULL;
    free(temp);
}
/*
void delete_beg() {
    if (head == NULL) {
        printf("List is already empty\n");
        return;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
}*/

int main() {
    // Insert 4 nodes
    insertion_front();
    insertion_front();
    insertion_front();
    insertion_front();
    display();
    delete_end();

    printf("\nLinked List after deleting from beginning:\n");
    display();

    return 0;
}





