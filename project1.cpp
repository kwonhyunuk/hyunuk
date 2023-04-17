#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 100

int* queue;
int	front;			// 전단
int	rear;			// 후단
int size = 1;

int isEmpty() {
	if (front == rear) return 1;
	else return 0;
}

// 큐가 포화 상태인지 확인하는 연산
int isFull() {
	if (front == (rear + 1) % QUEUE_SIZE) return 1;
	else return 0;
}

int queueSize() {
	return(rear - front + QUEUE_SIZE) % QUEUE_SIZE;
}

// 스택의 top에 원소를 삽입하는 연산
void enqueue(int item) {
	int* temp;

	if (isFull()) {
		printf(" Full QUEUE\n");
		size++;
		rear = (rear + 1) % (QUEUE_SIZE * size);
		queue[rear] = item;
	}
	else {
		rear = (rear + 1) % QUEUE_SIZE;
		queue[rear] = item;
	}
}

int dequeue() {
	if (isEmpty()) {	// 큐가 공백 상태인 경우
		printf("\n\n Queue is Empty!!\n");
		return 0;
	}
	else
	{
		if (rear % QUEUE_SIZE == 0)
		{
			size--;
		}
		front = (front + 1) % QUEUE_SIZE;
		return queue[front];
	}
	return 0;
}

// 큐의 원소를 출력하는 연산
void printQueue() {
	int i, maxi = rear;
	if (front >= rear) maxi += QUEUE_SIZE;
	printf("Queue size is [%d]= ", queueSize());
	for (i = front + 1; i <= QUEUE_SIZE * size; i++)
		printf("%d ", queue[i % QUEUE_SIZE]);
	printf("\n");
}


void insert(int index, int item) // 큐의 index번째 위치에 원소를 삽입
{
	int i, j;

	j = rear;
	
	for (i = 0; i < index; i++) 
	{
		j--;
		if (j < 0) 
			j = QUEUE_SIZE - 1;

		queue[(j + 1) % QUEUE_SIZE] = queue[j];
	}

	rear = (rear + 1) % QUEUE_SIZE;
	queue[(j + 1) % QUEUE_SIZE] = item;
}


int pop(int index) // 큐의 index번째 위치의 원소를 삭제하고 그 값을 반환
{
	int i, j;
	if (isEmpty()) 
	{
		printf("\n\n Queue is Empty!!\n");
		return 0;
	}
	
	j = front;
	
	for (i = 0; i < index; i++) 
	{
		j = (j + 1) % QUEUE_SIZE;
	}

	int item = queue[j];
	
	for (i = index; i > 0; i--)
	{
		queue[j] = queue[j - 1];
		j--;
		if (j < 0) 
			j = QUEUE_SIZE - 1;
	}
	front = (front + 1) % QUEUE_SIZE;
	return item;
}
void main(void) {
	int i;
	queue = (int*)malloc(QUEUE_SIZE * sizeof(int));

	for (i = 0; i < 9; i++) enqueue(i + 1);
	printQueue();
	for (i = 0; i < 7; i++) dequeue();
	printQueue();
	for (i = 10; i < 19; i++) enqueue(i + 1);
	printQueue();

	insert(4, 100);
	printQueue();
	free(queue);
	getchar();
}
