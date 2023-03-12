#include <iostream>
using namespace std;

struct Node
{
    //Structure of a Node
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
    //Creation of the Linked List!
    struct Node *temp, *last;
    Head = new Node;
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (int i = 1; i < n; i++)
    {
        temp = new Node;
        temp->data = A[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *p)
{
    //Display Method to print data in Nodes!
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
    cout << endl;
}

void Rdisplay(struct Node *p)
{ 
    //Recursive Method for display!
    static int flag = 0;
    if (p != Head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        Rdisplay(p->next);
    }
    flag = 0;
}
void insert(struct Node *p, int pos, int val)
{
    // Insert at a particular position(NOT INDEX)!
    Node *t, *q;
    q = p;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
    }
    t = new Node;
    t->data = val;
    t->next = p->next;
    p->next = t;
}
int main()
{
    int A[] = {2, 3, 4, 5, 6}; //Initiallizing Array
    create(A, 5); //Creating LL using Array
    // Rdisplay(Head);
    insert(Head, 4, 56); //Inserting at position 4 the value 56
    display(Head); //Displaying the LL after insertion
    return 0;
}