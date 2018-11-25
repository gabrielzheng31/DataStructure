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
