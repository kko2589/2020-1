#pragma once
#include <stdio.h>
#include <stdlib.h>

inline void error(const char* str) {
	fprintf(stderr, "%s\n", str);
	exit(1);
};

#define MAX_QUEUE_SIZE	10

class CircularQueue
{
protected:
	int	front;
	int	rear;
	int	data[MAX_QUEUE_SIZE];
//CircularQueue의 필요한 부분을 작성해라.
public:
CircularQueue(){front=rear=0;}
~CircularQueue(){}
int lastOp=0;
bool isEmpty(){return (lastOp==0)&&front==rear;}
bool isFull(){return (lastOp==1)&&front==(rear)%MAX_QUEUE_SIZE;}
void enqueue(int val){
	if(isFull()) data[rear]=data[rear];
	else{
		data[rear]=val;
		rear=(rear+1)%MAX_QUEUE_SIZE;
		lastOp=1;
	}
}
int dequeue(){
	if(isEmpty()) error(" Error : 큐 공백 오류\n");
	else{
		front=(front+1)%MAX_QUEUE_SIZE;
		lastOp=0;
		return data[front];
	}
}
void display(){
	printf("큐 내용 : ");
	int maxi=(front<rear)?rear:rear+MAX_QUEUE_SIZE;
	for(int i=front;i<maxi;i++)
		printf("[%2d] ",data[i%MAX_QUEUE_SIZE]);
	printf("\n");
}
	
};//class CircularQueue 끝



int main()
{
	CircularQueue que;
	for (int i = 1; i < 15; i++)
		que.enqueue(i);
	que.display();
	for (int i = 1; i < 6; i++) 
		que.dequeue();
	que.display();
	for (int i = 1; i < 15; i++)
		que.enqueue(i);		
	que.display();

	return 0;
}
