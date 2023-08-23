// Singly Circular LinkedList
// C
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE, **PPNODE;

void InsertFirst(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }

    else
    {
        newn->next = *Head;
        *Head = newn;
    }
    (*Tail)->next = *Head;
}

void InsertLast(PPNODE Head, PPNODE Tail, int iNo)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = iNo;
    newn->next = NULL;

    if((*Head == NULL) && (*Tail == NULL))
    {
        *Head = newn;
        *Tail = newn;
    }

    else
    {
        (*Tail)->next = newn;
        (*Tail) = (*Tail)->next;
    }
    (*Tail)->next = *Head;
}

void Display(PNODE Head, PNODE Tail)
{
    if(Head != NULL && Tail != NULL)
    {
        do
        {
            printf("| %d | -> ",Head->data);
            Head = Head->next;
        }while(Head != Tail->next);

        printf("\n");
    }
    else
    {
        printf("LL is empty \n");
    }
}

int Count(PNODE Head, PNODE Tail)
{
    int iCount = 0;

    if(Head != NULL && Tail != NULL)
    {
        do
        {
            iCount++;
            Head = Head->next;
        }while(Head != Tail->next);
        
        return iCount;
    }
    else
    {
        return 0;
    }
}

void DeleteFirst(PPNODE Head, PPNODE Tail)
{
    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }

    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }

    else
    {
        *Head = (*Head)->next;
        free((*Tail)->next);
        (*Tail)->next = *Head;
    }
}

void DeleteLast(PPNODE Head, PPNODE Tail)
{
    PNODE temp = *Head;

    if((*Head == NULL) && (*Tail == NULL))
    {
        return;
    }

    else if(*Head == *Tail)
    {
        free(*Head);
        *Head = NULL;
        *Tail = NULL;
    }

    else
    {
        while(temp->next != *Tail)
        {
            temp = temp->next;
        }
        free(*Tail);
        *Tail = temp;
        (*Tail)->next = *Head;
    }
}

void InsertAtPos(PPNODE Head, PPNODE Tail, int iNo, int iPos)
{
    int iLength = 0;
    iLength = Count(*Head,*Tail);
    int iCnt = 0;

    PNODE newn = NULL;
    PNODE temp = *Head;

    if((iPos < 1) || (iPos > iLength + 1))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(Head,Tail,iNo);
    }

    else if(iPos == iLength+1)
    {
        InsertLast(Head,Tail,iNo);
    }

    else
    {
        newn = (PNODE)malloc(sizeof(NODE));
        newn->data = iNo;
        newn->next = NULL;

        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

void DeleteAtPos(PPNODE Head, PPNODE Tail,int iPos)
{
    int iLength = 0;
    PNODE temp = *Head;
    int iCnt = 0;

    PNODE tempX = NULL;

    iLength = Count(*Head, *Tail);

    if((iPos < 1) || (iPos > iLength))
    {
        printf("Invalid position\n");
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(iPos == iLength)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(iCnt = 1; iCnt < iPos-1; iCnt++)
        {
            temp = temp -> next;
        }

        tempX = temp->next;

        temp->next = temp->next->next;
        free(tempX);
    }
}

int main()
{
    PNODE First = NULL;
    PNODE Last = NULL;

    int iRet = 0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);

    Display(First,Last);
    iRet = Count(First,Last);
    printf("Nodes in LL are : %d\n",iRet);

    InsertAtPos(&First,&Last,75,4);

    Display(First,Last);
    iRet = Count(First,Last);
    printf("Nodes in LL are : %d\n",iRet);

    DeleteAtPos(&First,&Last,4);

    Display(First,Last);
    iRet = Count(First,Last);
    printf("Nodes in LL are : %d\n",iRet);

    DeleteFirst(&First,&Last);
    DeleteLast(&First,&Last);

    Display(First,Last);
    iRet = Count(First,Last);
    printf("Nodes in LL are : %d\n",iRet);

    return 0;
}