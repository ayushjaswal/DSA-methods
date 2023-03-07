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
        cout << p->data << endl;
        p = p->next;
    }
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
    node * q;
    while (p != 0)
    {
        if (p->data == key)
        {
            //updated code for better performance
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
int main()
{

    int A[] = {3, 5, 7, 10, 15, 56};
    create(A, 6);
    Display(first);
    cout << "Number of Nodes are: " << count(first) << endl;
    cout << "Number of Nodes are: " << countRecursive(first) << endl;
    cout << "Sum of Nodes: " << sum(first) << endl;
    cout << "Sum of Nodes: " << sumRecursive(first) << endl;
    cout << "Maximum Element: " << MaxElm(first) << endl;
    cout << "Minimum Element: " << MinElm(first) << endl;
    cout << "Address of 7: " << Search(first, 7) << endl;
    cout << "Address of 7: " << SearchRecursive(first, 7) << endl;
    return 0;
}