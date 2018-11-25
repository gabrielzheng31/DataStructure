#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 16

typedef struct {
    int *base;
    int front, rear;
} SqQueue;

void InitQueue(SqQueue *sq_queue);
int QueueLength(SqQueue sq_queue);
void EnQueue(SqQueue *sq_queue, int elem);
void DeQueue(SqQueue *sq_queue, int *elem);

int main(void)
{
    SqQueue sq_queue;
    InitQueue(&sq_queue);
}

void InitQueue(SqQueue *sq_queue)
{
    sq_queue->base = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    if(sq_queue->base == NULL)
        exit(EXIT_FAILURE);
    sq_queue->front = sq_queue->rear = 0;
}

int QueueLength(SqQueue sq_queue)
{
    return (sq_queue.rear-sq_queue.front
            + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

void EnQueue(SqQueue *sq_queue, int elem)
{
    if((sq_queue->rear+1)%MAX_QUEUE_SIZE == sq_queue->front)
        exit(EXIT_FAILURE);
    sq_queue->base[sq_queue->rear] = elem;
    sq_queue->rear = (sq_queue->rear + 1)%MAX_QUEUE_SIZE;
}

void DeQueue(SqQueue *sq_queue, int *elem)
{
    if(sq_queue->rear == sq_queue->front)
        exit(EXIT_FAILURE);
    *elem = sq_queue->base[sq_queue->front];
    sq_queue->front = (sq_queue->front + 1) % MAX_QUEUE_SIZE;
}
