#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void DeleteMin(SqList *sq_list, int *value)
{
    if(sq_list->length == 0)
        exit(EXIT_FAILURE);
    *value = *sq_list->elem;
    int pos = 0;

    /*
     * Scan the list once to find the max of min.
     */
    for(int i = 1; i < sq_list->length; i++)
    {
        if(sq_list->elem[i] < *value)
        {
            *value = sq_list->elem[i];
            pos = i; 
        } 
    }
    sq_list->elem[pos] = sq_list->elem[sq_list->length-1];
    sq_list->length--;
}
