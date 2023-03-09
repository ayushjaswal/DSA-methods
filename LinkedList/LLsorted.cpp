#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    struct node *next;
} *first = NULL;

void create(int A[], int n)
{
    int i;
    struct node *t, *last;
    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int count(struct node *p)
{
    int c = 0;
    while (p != 0)
    {
        c++;
        p = p->next;
    }
    return c;
}
int countRecursive(struct node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return 1 + count(p->next);
    }
}
int sum(struct node *p)
{
    int sum = 0;
    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int sumRecursive(struct node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
    {
        return sumRecursive(p->next) + p->data;
    }
}
int MaxElm(struct node *p)
{
    int max = INT_MIN;
    while (p != 0)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }
    return max;
}
int MinElm(struct node *p)
{
    int min = INT_MAX;
    while (p != 0)
    {
        if (p->data < min)
        {
            min = p->data;
        }
        p = p->next;
    }
    return min;
}
node *Search(struct node *p, int key)
{
    node *q;
    while (p != 0)
    {
        if (p->data == key)
        {
            // updated code for better performance
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
node *SearchRecursive(struct node *p, int key)
{
    if (p == 0)
    {
        return NULL;
    }
    else
    {
        if (p->data == key)
        {
            return p;
        }
        else
        {
            SearchRecursive(p->next, key);
        }
    }
}
void insert(struct node *p, int value, int pos)
{
    node *t = new node;
    if (pos == 0)
    {
        t->data = value;
        t->next = first;
        first = t;
    }
    else
    {
        p = first;
        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

void insertSorted(struct node *p, int value)
{
    struct node *q;
    q = new node;
    node *t;
    t = new node;
    if (first == NULL)
    {
        t->data = value;
        t->next = NULL;
        first = t;
    }
    while (p && p->data < value)
    {
        q = p;
        p = p->next;
    }
    if (p == first)
    {
        t->data = value;
        t->next = first;
        first = t; // if the value is at first
    }
    else
    {
        t->data = value;
        t->next = p;
        q->next = t; // if it is any other general value
    }
}

void deleteidx(struct node *p, int idx)
{

    node *q;
    if (idx < 1 || idx > count(first))
    {
        cout << "WRONG INDEX!" << endl;
        return;
    }
    if (idx == 1)
    {
        p = first;
        first = first->next;
        cout << "Deleted Element: " << p->data << endl;
        delete p;
    }
    else
    {
        for (int i = 0; i < idx-1; i++)
        {
            q = p;
            p = p->next;
        }
        cout << "Deleted Element: " << p->data << endl;
        q->next = p->next;
        delete p;
    }
}
bool sorted(struct node *p){
    node * q;
    q = p->next;
    while(q != 0){
        if(p->data > q->data){
            return false;
        }
        p = q;
        q = p ->next;
    }
    return true;
}
int main()
{

    int A[] = {3, 5, 7, 10, 15, 56};
    create(A, 6);
    Display(first);
    if(sorted(first)){
        cout << "List Sorted!";
    }
    else{
        cout << "List Unsorted!";
    }
    return 0;
}