#include <stdio.h>
#include <stdlib.h>

typedef struct DLNode {
    int data;
    struct DLNode *prior, *next;
} DLNode, *DLinkList;

void InitDLinkList(DLinkList double_link_list, int n);
void PrintDLinkList(DLinkList double_link_list);

int main(void)
{
    DLinkList double_link_list = (DLinkList)malloc(sizeof(DLNode));
    if(double_link_list == NULL)
        exit(EXIT_FAILURE);
    InitDLinkList(double_link_list, 3);
    PrintDLinkList(double_link_list);
    return 0;
}

void InitDLinkList(DLinkList double_link_list, int n)
{
    DLNode *tail = double_link_list;
    for(int i = 0; i < n; i++)
    {
        DLNode *s = (DLNode *)malloc(sizeof(DLNode));
        scanf("%d", &s->data);
        s->prior = tail;
        tail->next = s;
        tail = s;
    }
    tail->next = NULL;
}

void InitDLinkListFromHead(DLinkList double_link_list, int n)
{
    DLNode *p = (DLNode *)malloc(sizeof(DLNode));
    scanf("%d", &p->data);
    for(int i = 0; i<n; i++)
    {
        p->next = double_link_list->next;
        if(double_link_list->next != NULL)
            double_link_list->next->prior = p; 
        p->prior = double_link_list;
        double_link_list->next = p;
    }
}

void PrintDLinkList(DLinkList double_link_list)
{
    DLNode *p = double_link_list->next;
    while(p)
    {
        printf("%d ", p->data); 
        p=p->next;
    }
    putchar('\n');
}

void InsertDLinkList(DLinkList double_link_list, int i, int elem)
{
    while(i < 1)
        exit(EXIT_FAILURE);
    DLNode *p = double_link_list;
    int j = 0;
    while(p && j<i-1)
    {
        p=p->next;
        j++;
    }
    if(!p)
        exit(EXIT_FAILURE);
    
    DLNode *s = (DLNode *)malloc(sizeof(DLNode));
    s->data = elem;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s; 
}

void DeleteDLinkListByIndex(DLinkList double_link_list, int i)
{
    DLNode *p = double_link_list;
    int j = 0;
    while(p->next && j<i-1)
    {
        p=p->next;
        j++; 
    }    
    if(!(p->next))
        exit(EXIT_FAILURE);
    DLNode *q =  p->next;
    p->next = q->next;
    if(q->next != NULL)
        q->next->prior = p;
    free(q);
}

