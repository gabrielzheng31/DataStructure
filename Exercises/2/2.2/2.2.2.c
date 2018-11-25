#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void Reverse(SqList *sq_list)
{
    int temp;
    /* Scan half of the list */
    for(int i = 0; i < sq_list->length/2; i++)
    {
        temp = sq_list->elem[i];
        /* The corresponding index (i & length-i-1)*/
        sq_list->elem[i] = sq_list->elem[sq_list->length-i-1];
        sq_list->elem[sq_list->length-i-1] = temp;
    }    
}
