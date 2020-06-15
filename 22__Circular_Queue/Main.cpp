// 코딩하시오.
#include <stdio.h>
#include <stdlib.h>

inline void error(char *str)
{
	fprintf(stderr,"%s\n",str);
	exit(1);
};

#define MAX_QUEUE_SIZE 100

class CircularQueue
{
	protected:
	int front;
	int rear;
	int data[MAX_QUEUE_SIZE];
	
	public:
	CircularQueue(){front=rear=0;}
	~CircularQueue(){}
	bool isEmpty(){return front==rear;}
	bool isFull(){return (rear+1)%MAX_QUEUE_SIZE==front;}
	void enqueue(int val){
		if(isFull())
			error(" error: 큐가 포화상태입니다\n");
		else{
			rear=(rear+1)%MAX_QUEUE_SIZE;
			data[rear]=val;
		}
	}
	int dequeue(){
		if(isEmpty())
			error(" Error: 큐가 공백상태입니다\n");
		else{
			front=(front+1)%MAX_QUEUE_SIZE;
			return data[front];
		}
	}
	int peek(){
		if(isEmpty())
			error(" Error: 큐가 공백상태입니다\n");
		else
			return data[(front+1)%MAX_QUEUE_SIZE];
	}
	void display(){
		printf("큐 내용 : ");
		int maxi=(front<rear)?rear:rear+MAX_QUEUE_SIZE;
		for(int i=front+1;i<=maxi;i++)
			printf("[%2d]",data[i%MAX_QUEUE_SIZE]);
		printf("\n");
	}
};

int main()
{
	CircularQueue que;
	for(int i=1;i<10;i++)
		que.enqueue(i);
	que.display();
	que.dequeue();
	que.dequeue();
	que.dequeue();
	que.display();
	
	return 0;
}