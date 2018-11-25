#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

typedef struct {
    int *base;
    int *top;
    int stack_size;
} SqStack;

void InitStack(SqStack *sq_stack)
{
    /*
     * sq_stack must be initialized outside InitStack!!
     * Initialize base, set top and stack_size.
     */
    sq_stack->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(sq_stack->base == NULL)
        exit(EXIT_FAILURE);
    sq_stack->top = sq_stack->base;
    sq_stack->stack_size = STACK_INIT_SIZE;
}

void GetTop(SqStack *sq_stack, int *elem)
{
    /*
     * The only thing to check is whether
     * the stack is empty(top==base).
     */
    if(sq_stack->top != sq_stack->base)
        *elem = *(sq_stack->top - 1);
}

void PushStack(SqStack *sq_stack, int elem)
{
    /*
     * Check whether the stack is full.
     */
    if(sq_stack->top-sq_stack->base >= sq_stack->stack_size)
    {
        sq_stack->base = (int *)realloc(sq_stack->base,
                (STACK_INCREMENT + sq_stack->stack_size)*sizeof(int));
        if(sq_stack->base == NULL)
            exit(EXIT_FAILURE);
        sq_stack->top = sq_stack->base + sq_stack->stack_size;
        sq_stack->stack_size += STACK_INCREMENT;
    }

    /* The "top" pointer will always point to the next place
     * of the last element. So, "*" will first get the value of
     * "top" then "++" will take top to next place.\
     */
    *sq_stack->top++ = elem;
}

void PopStack(SqStack *sq_stack, int *elem)
{
    /*
     * If not empty, pop up the last element.
     */
    if(sq_stack->top != sq_stack->base)
        /* Since the "top" pointer will always point to the next place
         * of the last element, we need to use "--" fisrt to go back to
         * the last element and then use "*" to get the value.
         */
        *elem = *--sq_stack->top;
}
