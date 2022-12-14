////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of doubly linear Linked list 
// 
//  11 ->21 ->51 ->101 ->121 ->151 ->NULL
// 
// ////////////////////////////////////////////////////////////////////////////////////



#include <iostream>
using namespace std;

typedef struct node
{
    int Data;
    struct node *next;
    struct node *prev;

} NODE, *PNODE, **PPNODE;

class DoublyLLL
{
private:
    PNODE head;
    int Count;

public:
    DoublyLLL();

    void Insertfirst(int iNo);

    void Insertlast(int iNo);

    void InsertAtPos(int iNo, int ipos);

    void Deletefirst();

    void Deletelast();

    void DeleteAtPos(int ipos);

    void Display();

    int CountNode();
};

DoublyLLL ::DoublyLLL()
{
    head = NULL;
    Count = 0;
}

void DoublyLLL ::Insertfirst(int iNo)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->Data = iNo;
    newn->prev = NULL;

    if ((head) == NULL)
    {
        head = newn;
    }
    else
    {
        newn->next = head;
        (head)->prev = newn;
        head = newn;
    }
    Count++;
}
void DoublyLLL ::Insertlast(int iNo)
{
    PNODE newn = new NODE;
    newn->next = NULL;
    newn->Data = iNo;
    newn->prev = NULL;

    if ((head) == NULL)
    {
        head = newn;
    }
    else
    {
        PNODE temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    Count++;
}
void DoublyLLL ::InsertAtPos(int iNo, int ipos)
{

    int Size = CountNode();

    if (ipos < 1 && ipos > (Size + 1))
    {
        return;
    }
    else if (ipos == 1)
    {
        Insertfirst(iNo);
    }
    else if (ipos == (Size + 1))
    {
        Insertlast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        newn->next = NULL;
        newn->Data = iNo;
        newn->prev = NULL;

        PNODE temp = head;
        int i = 0;
        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        newn->next->prev = newn;
        temp->next = newn;

        Count++;
    }
}
void DoublyLLL ::Deletefirst()
{
    if ((head) == NULL)
    {
        return;
    }
    else
    {
        PNODE tempdelete = head;
        head = (head)->next;
        (head)->prev = NULL;

        free(tempdelete);
    }
    Count--;
}
void DoublyLLL ::Deletelast()
{
    if ((head) == NULL)
    {
        return;
    }
    else
    {
        PNODE temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
    Count--;
}
void DoublyLLL ::DeleteAtPos(int ipos)
{
    int Size = CountNode();

    if (ipos < 1 && ipos > (Size))
    {
        return;
    }
    else if (ipos == 1)
    {
        Deletefirst();
    }
    else if (ipos == (Size))
    {
        Deletelast();
    }
    else
    {

        PNODE temp = head;

        int i = 0;

        for (i = 1; i < (ipos - 1); i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(temp->next->prev);
        temp->next->prev = temp;

        Count--;
    }
}

void DoublyLLL ::Display()
{
    PNODE temp = head;

    while ((temp) != NULL)
    {
        printf("%d ->", (temp->Data));

        temp = temp->next;
    }

    printf("NULL\n");
}

int DoublyLLL ::CountNode()
{
    return Count;
}

int main()
{
    DoublyLLL obj;
    obj.Insertfirst(51);
    obj.Insertfirst(21);
    obj.Insertfirst(11);
    obj.Display();
    int iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    obj.Insertlast(101);
    obj.Insertlast(121);
    obj.Insertlast(151);

    obj.Display();
    iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    obj.InsertAtPos(1, 1);
    obj.InsertAtPos(171, 8);
    obj.InsertAtPos(71, 5);
    obj.Display();
    iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    obj.Deletefirst();
    obj.Deletefirst();
    obj.Display();
    iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    obj.Deletelast();
    obj.Display();
    iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    obj.DeleteAtPos(1);
    obj.DeleteAtPos(5);
    obj.DeleteAtPos(3);
    obj.Display();
    iret = obj.CountNode();
    cout << "Number of nodes in linked list are " << iret << endl;

    return 0;
}
