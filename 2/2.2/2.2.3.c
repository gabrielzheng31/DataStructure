typedef struct {
	int *elem;
	int length;
	int list_size;
} SqList;

void DelX1(SqList *sq_list, int x)
{
    /*
     * var k is used to record the remaining
     * elements' index while i is the original one.
     */
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

void DelX2(SqList *sq_list, int x)
{
    /* 
     * var k is used to record the num of elem x.
     */
    int k = 0;
    for(int i = 0; i < sq_list->length; i++)
    {
        if(sq_list->elem[i] == x)
            k++;
        else
            sq_list->elem[i-k] = sq_list->elem[i];
    }
    sq_list->length -= k;
}
