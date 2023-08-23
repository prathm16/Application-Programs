#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node * next;
}NODE, *PNODE, **PPNODE;

void Display(PNODE Head)
{
    printf("Elements of Stack are : \n");

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

void Push(PPNODE Head, int No)
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

int Pop(PPNODE Head)
{
    int Value = 0;
    PNODE temp = *Head;

    if(*Head == NULL)
    {
        printf("Stack is empty \n");
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
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Value = temp->next->data;
        free(temp->next);
        temp->next = NULL;
    }
    return Value;
}

int main()
{
    PNODE First = NULL;
    int iRet = 0;

    Push(&First,11);
    Push(&First,21);

    Display(First);
    iRet = Count(First);
    printf("Number of elements are : %d\n",iRet);

    iRet = Pop(&First);
    printf("Poped elements from stack is : %d\n",iRet);

    iRet = Pop(&First);
    printf("Poped elements from stack is : %d\n",iRet);

    iRet = Pop(&First);
    
    return 0;
}