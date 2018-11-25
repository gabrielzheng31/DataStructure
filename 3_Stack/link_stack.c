#include <stdio.h>
#include <stdlib.h>

typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LStack;

int main(void)
{
    LStack link_stack = (LNode *)malloc(sizeof(LNode));
    if(link_stack == NULL)
        exit(EXIT_FAILURE);
    link_stack->next = NULL;
}

void PushLinkStack(LStack link_stack, int elem)
{
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL)
        exit(EXIT_FAILURE);
    p->data = elem;
    p->next = link_stack->next;
    link_stack->next = p;    
}

