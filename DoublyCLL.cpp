////////////////////////////////////////////////////////////////////////////////////////
// 
// These file conatains source code of doubly circular Linked list 
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
    struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

class SinglyCLL
{
private: // Charecteristics
    PNODE Head;
    PNODE Tail;

public:         // Behaviours
    SinglyCLL() // Default constructor
    {
        Head = NULL;
        Tail = NULL;
    }

    void InsertFirst(int iNo)
    {
        PNODE newn = NULL;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        if (Head == NULL && Tail == NULL) // If link list is empty..........
        {
            Head = newn;
            Tail = newn;
        }

        else // If link list contains more than one node
        {
            newn->next = Head;
            newn->prev = Tail;
            Tail->next = newn;
            Head->prev = newn;
            Head = newn;
        }
    }

    void InsertLast(int iNo)
    {
        PNODE newn = NULL;
        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        if (Head == NULL && Tail == NULL) // If link list is empty.........
        {
            Head = newn;
            Tail = newn;
        }

        else // If link list contains more than one node
        {
            newn->next = Head;
            newn->prev = Tail;
            Tail->next = newn;
            Head->prev = newn;
            Tail = newn;
        }
    }

    void InsertAtPos(int iNo, int ipos)
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
            newn->prev = NULL;

            for (iCnt = 1; iCnt < (ipos - 1); iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            newn->prev = temp;
            temp->next->prev = newn;
            temp->next = newn;
        }
    }
    void DeleteFirst()
    {

        if (Head == NULL && Tail == NULL)
        {
            return;
        }

        else if (Head == Tail)
        {
            free(Head);
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            Tail->next = Head->next;
            free(Head);
            Head = Tail->next;
            Head->prev = Tail;
        }
    }

    void DeleteLast()
    {

        if (Head == NULL && Tail == NULL)
        {
            return;
        }

        else if (Head == Tail)
        {
            free(Head);
            Head = NULL;
            Tail = NULL;
        }
        else
        {
            PNODE tempdelete = Tail;
            Tail->prev->next = Head;
            Head->prev = Tail->prev;
            Tail = Tail->prev;
            free(tempdelete);
        }
    }

    void DeleteAtPos(int ipos)
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

            PNODE tempDelete = temp->next;
            temp->next = temp->next->next;
            temp->next->prev = temp;
            free(tempDelete);
        }
    }

    void Display()
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

    int Count()
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
};

int main()
{
    int iRet = 0;
    SinglyCLL obj;

    obj.InsertFirst(101);
    obj.InsertFirst(51);
    obj.InsertFirst(31);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.InsertLast(121);
    obj.InsertLast(151);
    obj.InsertLast(171);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteFirst();
    obj.DeleteFirst();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteLast();
    obj.DeleteLast();

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.InsertAtPos(61, 3);
    obj.InsertAtPos(71, 4);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj.DeleteAtPos(3);
    obj.DeleteAtPos(3);

    obj.Display();
    iRet = obj.Count();
    cout << "Number of nodes are :" << iRet << endl;

    return 0;
}