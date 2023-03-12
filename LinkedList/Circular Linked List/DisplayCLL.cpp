#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *Head;

void create(int A[], int n)
{
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
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != Head);
    cout << endl;
}

void Rdisplay(struct Node *p)
{
    static int flag = 0;
    if(p != Head || flag == 0){
        flag = 1;
        cout << p->data << " ";
        Rdisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    Rdisplay(Head);
    return 0;
}