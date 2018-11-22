#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void Merge(SqList sq_list_a, SqList sq_list_b, SqList *sq_list_c)
{
    if(sq_list_a.length + sq_list_b.length > sq_list_c->length)
       exit(EXIT_FAILURE);
    int i=0, j=0, k=0;
    while(i<sq_list_a.length && j<sq_list_b.length)
    {
        if(sq_list_a.elem[i] < sq_list_b.elem[j])
           sq_list_c->elem[k++] = sq_list_a.elem[i++];
        else
           sq_list_c->elem[k++] = sq_list_b.elem[j++]; 
    }
    while(i < sq_list_a.length)
        sq_list_c->elem[k++] = sq_list_a.elem[i++];
    while(i < sq_list_b.length)
        sq_list_c->elem[k++] = sq_list_b.elem[j++];
    sq_list_c->length = ++k; 
}
