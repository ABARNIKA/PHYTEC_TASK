#include<stdio.h>
#include<stdlib.h>
#define n 25
int queue[n];
int front=-1;
int rear=-1;
void enqueue(int x){
       	if(front ==-1 && rear ==-1)
        {
                front=rear=0;
                queue[rear]=x;
        }
	else if(((rear+1)%n)==front)
	{
		printf("Queue is full");
	}
        else{
                rear=(rear+1)%n;
                queue[rear]=x;
        }
}
void dequeue()
{
        if(front==-1 && rear==-1)
        {
                printf("Queue is empty\n");
        }
        else if(front == rear)
        {
		printf("deleted Queue:%d",queue[front]);
                front=rear=-1;
        }
        else
        {
                printf("\nDeleted Queue:%d\n",queue[front]);
                front=(front+1)%n;

        }
}
void display()
{
	int i=front;
        if(front ==-1 && rear ==-1)
        {
                printf("Queue is full\n");
        }
        else {
                printf("Queue contains:");
		while(i!=rear)
		{
			printf("%d ",queue[i]);
			i=(i+1)%n;
		}
		printf("%d",queue[rear]);
        }
}
void peek()
{
        if(front ==-1 && rear ==-1)
        {
                printf("Queue is full\n");
        }
        else
        {
                printf("\nThe peek element is:%d\n",queue[front]);
        }
}
int main()
{

        enqueue(10);
        enqueue(20);
        enqueue(30);
        enqueue(40);
	enqueue(50);
        dequeue();
        display();
        peek();
        dequeue();
	enqueue(60);
	enqueue(70);
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();
	dequeue();

}

