#include <iostream>
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

int count(struct node *p){
    int c= 0;
    while( p != 0){
        c++;
        p = p->next;
    }
    return c;
}
int countRecursive(struct node *p){
    if(p == 0){
        return 0;
    }
    else{
        return 1+count(p->next);
    }
}
int sum(struct node *p){
    int sum = 0;
    while(p != 0){
        sum += p->data;
        p = p->next;
    }
    return sum;
}
int sumRecursive(struct node *p){
    if(p == 0){
        return 0;
    }
    else{
        return sumRecursive(p->next) + p->data; 
    }
}
int main()
{

    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    Display(first);
    cout << "Number of Nodes are: " << count(first) << endl;
    cout << "Number of Nodes are: " << countRecursive(first) << endl;
    cout << "Sum of Nodes: " << sum(first) << endl;
    cout << "Sum of Nodes: " << sumRecursive(first) << endl;
    return 0;
}