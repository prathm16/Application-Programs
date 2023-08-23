// Singly Linear LinkedList
// C
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, int ino)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = ino;
    newn->next = NULL;

    if(*Head == NULL)
    {
        *Head = newn;
    }

    else
    {
        newn->next = *Head;
        *Head = newn;
    }
}

void InsertLast(PPNODE Head, int ino)
{
    PNODE newn = NULL;
    PNODE temp = *Head;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = ino;
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

void Display(PNODE Head)
{
    printf("Elements in the LL are : \n");

    while(Head != NULL)
    {
        printf(" | %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL \n");
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

void DeleteFirst(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }

    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }

    else
    {
        *Head = (*Head)->next;
        free(temp);
    }
}

void DeleteLast(PPNODE Head)
{
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        return;
    }

    else if((*Head)->next == NULL)
    {
        free(*Head);
        *Head = NULL;
    }

    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void InsertAtPos(PPNODE Head, int ino, int ipos)
{
    int iLength = 0;
    iLength = Count(*Head);

    PNODE temp = *Head;
    int iCnt = 0;
    PNODE newn = NULL;

    if((ipos < 1) || (ipos > iLength+1))
    {
        printf("Invalid position \n");
        return;
    }

    if(ipos == 1)
    {
        InsertFirst(Head, ino);
    }

    else if(ipos == iLength+1)
    {
        InsertLast(Head,ino);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = ino;
        newn->next= NULL;

        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, int ipos)
{
    int iLength = 0;
    iLength = Count(*Head);
    PNODE tempX = NULL;

    PNODE temp = *Head;
    int iCnt = 0;

    if((ipos < 1) || (ipos > iLength))
    {
        printf("Invalid position \n");
        return;
    }

    if(ipos == 1)
    {
        DeleteFirst(Head);
    }

    else if(ipos == iLength)
    {
        DeleteLast(Head);
    }

    else
    {
        for(iCnt = 1; iCnt < ipos-1; iCnt++)
        {
            temp = temp->next;
        }
        tempX = temp->next;
        temp->next = temp->next->next;
        free(tempX);
    }
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    InsertFirst(&First, 51);
    InsertFirst(&First, 21);
    InsertFirst(&First, 11);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes in LL are : %d\n",iRet);

    InsertLast(&First,101);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes in LL are : %d\n",iRet);

    InsertAtPos(&First, 30, 3);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes in LL are : %d\n",iRet);

    DeleteAtPos(&First,3);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes in LL are : %d\n",iRet);

    DeleteFirst(&First);
    DeleteLast(&First);

    Display(First);
    iRet = Count(First);
    printf("Number of nodes in LL are : %d\n",iRet);

    return 0;
}