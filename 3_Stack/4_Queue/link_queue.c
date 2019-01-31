#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode;

typedef struct {
    LNode *front, *rear;
} LinkQueue;

void InitLinkQueue(LinkQueue *link_queue)
{
    link_queue->front = link_queue->rear
        = (LNode *)malloc(sizeof(LNode));
    if(link_queue->front == NULL)
        exit(EXIT_FAILURE);
    /* 
     * Since front/rear points to the address,
     * we only need to revise front/rear alone.
     * (which is said that front is same)
     */
    link_queue->front->next = NULL;
}

void EnLinkQueue(LinkQueue *link_queue, int elem)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL)
        exit(EXIT_FAILURE);
    p->data = elem;
    p->next = NULL;
    link_queue->rear->next = p;
    link_queue->rear = p;
}

void DeLinkQueue(LinkQueue *link_queue, int *elem)
{
    if(link_queue->rear == link_queue->front)
        exit(EXIT_FAILURE);
    LNode *p = link_queue->front->next;
    *elem = p->data;
    link_queue->front->next = p->next;
    if(link_queue->rear == p)
        link_queue->rear = link_queue->front;
    free(p);
}
