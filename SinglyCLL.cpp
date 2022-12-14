////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of singly circular Linked list 
// 
//  11 ->21 ->51 ->101 ->121 ->151 ->NULL
// 
// ////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyCLL
{
private: // Charecteristics
    PNODE Head;
    PNODE Tail;

public:          // Behaviours
    SinglyCLL(); // Default constructor

    void InsertFirst(int iNo);

    void InsertLast(int iNo);

    void InsertAtPos(int iNo, int ipos);

    void DeleteFirst();

    void DeleteLast();

    void DeleteAtPos(int ipos);

    void Display();

    int Count();
};

SinglyCLL ::SinglyCLL() // Default constructor
{
    Head = NULL;
    Tail = NULL;
}

void SinglyCLL ::InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL contains at least one node
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
}

void SinglyCLL ::InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->data = iNo;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        Head = newn;
        Tail = newn;
    }
    else // If LL contains at least one node
    {

        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

void SinglyCLL ::InsertAtPos(int iNo, int ipos)
{
    int iSize = 0;

    iSize = Count();

    if ((ipos < 1) && ipos > (iSize + 1))
    {
        cout << "Invalid position\n";
    }

    else if (ipos == 1)
    {
        InsertFirst(iNo);
    }
    else if (ipos == (iSize + 1))
    {
        InsertLast(iNo);
    }

    else
    {
        int iCnt = 0;
        PNODE temp = Head;

        PNODE newn = NULL;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

void SinglyCLL ::DeleteFirst()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains at least one node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else
    {
        Tail->next = Head->next;
        delete Head;
        Head = Tail->next;
    }
}

void SinglyCLL ::DeleteLast()
{
    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    else if (Head == Tail) // If LL contains at least one node
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }

    else // If link list contain more than  node..............
    {
        PNODE temp = Head;
        while (temp->next != Tail)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = Head;
        Tail = temp;
    }
}

void SinglyCLL ::DeleteAtPos(int ipos)
{
    int iSize = 0;

    iSize = Count();

    if ((ipos < 1) && ipos > (iSize))
    {
        cout << "Invalid position\n";
    }

    else if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == (iSize))
    {
        DeleteLast();
    }

    else
    {
        int iCnt = 0;
        PNODE temp = Head;

        for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
        {
            temp = temp->next;
        }

        PNODE tempdelete = temp->next;
        temp->next = temp->next->next;
        free(tempdelete);
    }
}

void SinglyCLL ::Display()
{
    PNODE temp = Head;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return;
    }
    do
    {
        cout << "|" << temp->data << "|-> ";
        temp = temp->next;

    } while (temp != Tail->next);

    cout << "NULL";
    cout << endl;
}

int SinglyCLL ::Count()
{
    PNODE temp = Head;
    int iCnt = 0;

    if ((Head == NULL) && (Tail == NULL)) // If LL is empty
    {
        return 0;
    }
    do
    {
        iCnt++;
        temp = temp->next;

    } while (temp != Tail->next);

    return iCnt;
}

int main()
{
    int iRet = 0;

    SinglyCLL obj;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.InsertLast(101);
    obj.InsertLast(111);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteFirst();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteLast();
    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.InsertAtPos(31, 1);
    obj.InsertAtPos(41, 4);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteAtPos(3);
    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    return 0;
}