#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10
#define true 0
#define false 1
typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

int InitSqList(SqList *sq_list);
//int DestroySqList(SqList *sq_list);
int InsertSqListElem(SqList *sq_list, int location, int num);
int DeleteSqListElem(SqList *sq_list, int location, int *num);

int main()
{
    SqList *sq_list = (SqList *)malloc(sizeof(SqList));
    InitSqList(sq_list);
    sq_list->elem[0] = 0;
    sq_list->elem[1] = 1;
    sq_list->elem[2] = 2;
    sq_list->length = 3;
    InsertSqListElem(sq_list, 1, 10);
    for(int i = 0; i < sq_list->length; i++)
        printf("%d\n", sq_list->elem[i]);

    int *num = (int *)malloc(sizeof(int));
    DeleteSqListElem(sq_list, 3, num);
    for(int i = 0; i < sq_list->length; i++)
        printf("%d\n", sq_list->elem[i]);
    return 0;
}

int InitSqList(SqList *sq_list)
{
	sq_list->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (sq_list->elem == NULL) exit(EXIT_FAILURE);
	sq_list->length = 0;
	sq_list->list_size = LIST_INIT_SIZE;
	return true;
}

int InsertSqListElem(SqList *sq_list, int location, int num)
{
	if (location<1 || location>sq_list->length + 1)
		exit(EXIT_FAILURE);
	if (sq_list->length >= sq_list->list_size) {
		int *newbase = (int *)realloc(sq_list->elem, 
			(LIST_INCREMENT + sq_list->list_size) * sizeof(int));
		if (newbase == NULL) exit(EXIT_FAILURE);
		sq_list->elem = newbase;
		sq_list->list_size += LIST_INCREMENT;
	}
	int *begin = sq_list->elem + location - 1;
	int *end = sq_list->elem + sq_list->length - 1;
	/*
	 *    Since elements need to be moved backward,
	 *  we should start it from the end of the list.
	 *  If we start from the front of the list, 
	 *  the following elements will be covered.
	 */
	for (; end >= begin; end--)
		*(end + 1) = *end;
	sq_list->elem[location] = num;
	sq_list->length++;
	return true;
}

int DeleteSqListElem(SqList *sq_list, int location, int *num)
{
	if (location<1 || location>sq_list->length)
		exit(EXIT_FAILURE);
	sq_list->elem[location - 1] = *num;
	int *begin = sq_list->elem + location - 1;
	int *end = sq_list->elem + sq_list->length - 1;
	/*
	 *    Since elements need to be moved foreward,
	 *  we should start it from the beginning of the list.
	 *  If we start from the end of the list,
	 *  the elements ahead will be covered.
	 */
	for (; begin <= end; begin++)
		*(begin + 1) = *begin;
	sq_list->length--;
	return true;
}


