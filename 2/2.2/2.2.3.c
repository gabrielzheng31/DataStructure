typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void DelX(SqList *sq_list, int x)
{
    int k = 0;
    for(int i = 0; i < sq_list->length; i++)
    {
        if(sq_list->elem[i] != x)
        {
            sq_list->elem[k] = sq_list->elem[i];
            k++; 
        } 
    }
    sq_list->length = k;
}
