////////////////////////////////////////////////////////////////////////////////////////
//
// These file conatains source code of singly linear Linked list
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

class SinglyLinearLL
{
private:
    PNODE head;

public:
    SinglyLinearLL();

    void InsertFirst(int iNo);
    void InsertAtPos(int iNo, int pos);
    void InsertLast(int iNo);
    void DeleteFirst();
    void DeleteAtPos(int Pos);
    void DeleteLast();
    void Display();
    int Count();
};

SinglyLinearLL ::SinglyLinearLL()
{
    head = NULL;
}

void SinglyLinearLL ::InsertFirst(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = iNo;

    if (head == NULL)
    {
        head = newn;
    }

    else
    {
        newn->next = head;
        head = newn;
    }
}
void SinglyLinearLL ::InsertAtPos(int iNo, int Pos)
{
    int iSize = 0;
    int iCnt = 0;

    iSize = Count();

    if (Pos < 1 && Pos > (iSize + 1))
    {
        cout << "Invalid Position\n";
    }

    else if (Pos == 1)
    {
        InsertFirst(iNo);
    }
    else if (Pos == (iSize + 1))
    {
        InsertLast(iNo);
    }

    else
    {
        PNODE newn = NULL;

        newn = new NODE;

        newn->data = iNo;
        newn->next = NULL;

        PNODE temp = NULL;

        temp = head;

        for (iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}
void SinglyLinearLL ::InsertLast(int iNo)
{
    PNODE newn = NULL;

    newn = new NODE;

    newn->next = NULL;
    newn->data = iNo;

    if (head == NULL)
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
    }
}
void SinglyLinearLL ::DeleteFirst()
{
    PNODE temp = head;

    if (head == NULL)
    {
        return;
    }

    else
    {
        head = head->next;
        free(temp);
    }
}
void SinglyLinearLL ::DeleteAtPos(int Pos)
{
    int iSize = 0;
    int iCnt = 0;

    iSize = Count();

    if (Pos < 1 && Pos > (iSize))
    {
        cout << "Invalid Position\n";
    }

    else if (Pos == 1)
    {
        DeleteFirst();
    }
    else if (Pos == (iSize))
    {
        DeleteLast();
    }

    else
    {

        PNODE temp = NULL;
        PNODE tempDelete = NULL;

        temp = head;
        tempDelete = head;

        for (iCnt = 1; iCnt < (Pos - 1); iCnt++)
        {
            temp = temp->next;
        }
        tempDelete = temp->next;
        temp->next = temp->next->next;
        free(tempDelete);
    }
}
void SinglyLinearLL ::DeleteLast()
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
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
}

void SinglyLinearLL ::Display()
{
    cout << "Elements of link list are :\n";
    PNODE temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";

        temp = temp->next;
    }

    cout << "Null\n";
}

int SinglyLinearLL ::Count()
{
    int iCnt = 0;
    PNODE temp = head;
    while (temp != NULL)
    {
        iCnt++;

        temp = temp->next;
    }
    return iCnt;
}

int main()
{
    int iRet = 0;

    SinglyLinearLL obj1;

    obj1.InsertFirst(51);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);
    obj1.InsertLast(101);
    obj1.InsertLast(121);

    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj1.DeleteFirst();
    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj1.DeleteLast();
    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj1.InsertAtPos(31, 3);
    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj1.InsertAtPos(41, 4);
    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    obj1.DeleteAtPos(3);
    obj1.Display();
    iRet = obj1.Count();
    cout << "Number of nodes are :" << iRet << endl;

    return 0;
}