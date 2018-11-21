#include <stdio.h>
#include <stdlib.h>


typedef struct LNode {
    int data;
    struct LNode *next;
} LNode, *LinkList;

void CreateLinkList(LinkList link_list, int num);
void InvertCreateLinkList(LinkList link_list, int num);
void PrintLinkList(LinkList link_list);
LNode *GetElemByIndex(LinkList link_list, int i);
int LocaleElemByValue(LinkList link_list, int value);
void InsertLinkList(LinkList link_list, int index, int elem);
void DeleteElemByIndex(LinkList link_list, int i);

int main(void)
{
    LinkList link_list = (LinkList)malloc(sizeof(LNode));
    if(link_list == NULL)
        exit(EXIT_FAILURE);
    CreateLinkList(link_list, 3);
    PrintLinkList(link_list);
    for(int i = 0; i < 5; i++)
    {
        printf("NO.%d: %p\n", i, GetElemByIndex(link_list, i)); 
    } 
    InsertLinkList(link_list, 2, 11);
    printf("index: %d\n", LocaleElemByValue(link_list, 3));
    PrintLinkList(link_list);
    return 0;
}



/*
 *    List "link_list" must be initialized before passing
 *  to the function!!!
 */
void CreateLinkList(LinkList link_list, int num)
{
    LNode *tail = link_list;
    for(int i = 0; i < num; i++)
    {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &node->data);
        tail->next = node;   
        tail = node;
    }
    tail->next = NULL;
} 

/*
 *    List "link_list" must be initialized before passing
 *  to the function!!!
 */
void InvertCreateLinkList(LinkList link_list, int num)
{
    for(int i = 0; i < num; i++)
    {
        LNode *node = (LNode *)malloc(sizeof(LNode));
        scanf("%d", &node->data);
        node->next = link_list->next;
        link_list->next = node;
    }
}

void PrintLinkList(LinkList link_list)
{
    LNode *p = link_list->next;
    for(; p != NULL; p=p->next)
        printf("%d\n", p->data);
}

LNode *GetElemByIndex(LinkList link_list, int i)
{
    /*
     * Test whether index i is a negative number.
     */
    if(i < 1)
        return NULL;

    /* 
     * Set a pointer pointing to the header.
     */
    LNode *p = link_list;
    int j = 0;

    /*
     * Run to p_i.
     */
    while(p && j<i)
    {
        p = p->next;
        j++;        
    }

    /*
     * if the index is greater than the length,
     * then the pointer will be NULL.
     */
    return p;
}

int LocaleElemByValue(LinkList link_list, int value)
{
    LNode *p = link_list->next;
    int j = 1;
    while(p && p->data != value)
    {
        p = p->next;
        j++;
    }
    if(p != NULL)
        return j;
    else
        return 0;
}

void InsertLinkList(LinkList link_list, int i, int elem)
{
    /*
     * Test whether index i is a negative number.
     */
    if(i < 1)
        exit(EXIT_FAILURE);

    /*
     * Set a node pointer that points to the header.
     */
    LNode *node = link_list;
    int j = 0;

    /* 
     * run to p(i-1).
     * So will the empty list.
     */
    while(node && j<i-1)
    {
        node = node->next;
        j++; 
    }

    /*
     * Test whether index i cross the boundary.
     */
    if(!node)
        exit(EXIT_FAILURE);

    /*
     * dealing with data
     */
    LNode *temp = (LNode *)malloc(sizeof(LNode));
    temp->data = elem;
    temp->next = node->next;
    node->next = temp;
}

void DeleteElemByIndex(LinkList link_list, int i)
{
    if(i<1)
        exit(EXIT_FAILURE);

    LNode *p = link_list;
    int j = 0;

    while(p&&j<i-1)
    {
        p=p->next;
        j++;
    }
    
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}
