#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void DeleteSame(SqList *sq_list)
{
    if(sq_list->length == 0)
        exit(EXIT_FAILURE);
    int i, j;
    for(i = 0, j = 1; j < sq_list->length; j++)
        if(sq_list->elem[i] != sq_list->elem[j])
            sq_list->elem[++i] = sq_list->elem[j];
    sq_list->length = ++i;
}
