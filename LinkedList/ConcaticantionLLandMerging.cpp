#include <iostream>
#include <climits>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*first = NULL, *second = NULL, *third = NULL;

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
void create2(int A[], int n)
{
    int i;
    struct node *t, *last;
    second = new node;
    second->data = A[0];
    second->next = NULL;
    last = second;

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
        for (int i = 0; i < idx - 1; i++)
        {
            q = p;
            p = p->next;
        }
        cout << "Deleted Element: " << p->data << endl;
        q->next = p->next;
        delete p;
    }
}
bool sorted(struct node *p)
{
    node *q;
    q = p->next;
    while (q != 0)
    {
        if (p->data > q->data)
        {
            return false;
        }
        p = q;
        q = p->next;
    }
    return true;
}
void dupliRemove(struct node *p)
{
    node *q;
    q = p->next;
    while (q != 0)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
}
void LLreverselinks(struct node *p)
{
    node * q = NULL, * r = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void LLreverseArray(struct node *p)
{
    int i = 0, * A;
    node *q = p;
    A = new int[count(first)];

    while( q != NULL)
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }

    q = p;
    i--;
    while(q != NULL)
    {
        q -> data = A[i];
        q = q->next;
        i--;
    }
}
void LLreverseRecursive(struct node *p, struct node * q)
{   
    if(p)
    {
        LLreverseRecursive(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
void concat(struct node *p, struct node * q){

    third = p;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = q;
}
node * merging(struct node *p, struct node *q){
    struct node *last, *third, *first, *second;
        first = p;
        second = q;
        if(first && second)
        {    if(first->data < second->data){
                last = third = first;
                first = first->next;
                last->next = NULL;
            }
            else{ 
                last = third = second;
                second = second->next;
                last->next = NULL;
            }
            while(first && second){
                if(first->data < second->data){
                    last->next = first;
                    last = first;
                    first = first->next;
                    last->next=NULL;
                }
                else{
                    last->next = second;
                    last = second;
                    second = second->next;
                    last->next=NULL;
                }
            }
            if(first){
                last->next = first;
            }
            else if (second){
                last->next = second;
            }
        }
        else if(first && second == NULL){
            third = first;
        }
        else if(first == NULL && second){
            third = second;
        }
        else{
            return NULL;
        }
        return third;
}
int main()
{
    int A[] = {3, 5, 7, 10, 15, 56};
    int B[] = {1, 2, 4, 6, 8, 11};
    create(A, 6);
    create2(B, 6);
    Display(first);
    Display(second);
    // concat(first, second);
    // Display(third);
    Display(merging(first, second));
    return 0;
}