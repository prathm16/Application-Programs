#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head)
{
    printf("Elements of Queue are : \n");

    while(Head != NULL)
    {
        printf("%d\n",Head->data);
        Head = Head->next;
    }
    printf("\n");
}

int Count(PNODE Head)
{
    int iCount = 0;

    while(Head != NULL)
    {
        iCount++;
        Head = Head->next;
    }
    return iCount;
}

void Enqueue(PPNODE Head, int No)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = No;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

int Dequeue(PPNODE Head)
{
    int Value = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Queue is empty \n");
        return -1;
    }

    else if((*Head)->next == NULL)
    {
        Value = (*Head)->data;
        free(*Head);
        *Head = NULL;
    }

    else
    {
        Value = (*Head)->data;
        *Head = (*Head)->next;
        free(temp);
    }
    return Value;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Enqueue(&First, 11);
    Enqueue(&First, 21);
    Enqueue(&First, 51);

    Display(First);
    iRet = Count(First);
    printf("Number of elements in Queue are : %d\n",iRet);

    iRet = Dequeue(&First);
    printf("Removed element from Queue is : %d\n",iRet);

    iRet = Dequeue(&First);
    printf("Removed element from Queue is : %d\n",iRet);

    iRet = Dequeue(&First);
    printf("Removed element from Queue is : %d\n",iRet);

    iRet = Dequeue(&First);
   

    
    return 0;
}