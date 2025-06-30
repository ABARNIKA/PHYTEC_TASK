#include<stdio.h>
#include<stdlib.h>
#define n 25
int queue[n];
int front=-1;
int rear=-1;
void enqueue(int x){
	if(rear== n-1)
	{
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=x;
	}
	else{
		rear++;
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
		front=rear=-1;
	}
	else
	{
		printf("\nDeleted Queue:%d\n",queue[front]);
		front++;
	}
}
void display()
{
	if(front ==-1 && rear ==-1)
        {
                printf("Queue is empty\n");
        }
	else {
		printf("Queue contains:");
		for(int i=front;i<rear+1;i++)
		{
			printf("%d ",queue[i]);
		}
	}
}
void peek()
{
	if(front ==-1 && rear ==-1)
        {
                printf("Queue is empty\n");
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
	display();
	dequeue();
	display();
	peek();
	dequeue();
}


