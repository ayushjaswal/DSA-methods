#include <iostream>
using namespace std;

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first =NULL;

void create(int A[], int n){
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    
    for(int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = last->next;
        last->next = t;
        last = t;

    }
}

void Display(struct Node *p){
    while(p){
        cout<< p->data << endl;
        p = p->next;
    }
}

int Length(struct Node * p){
    int len =0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void insertInto(struct Node * p, int index, int val){
    struct Node *t;
    int i; 
    if(index < 0 || index > Length(p)){
        return;
    }
    else{
        if(index == 0){
            t = new Node;
            t->data = val;
            t->next = first;
            t->prev = NULL;
            first->prev = t;
            first = t;
        }
        else{
             for(i = 0; i < index -1; i++){
                p = p->next;
             }
             t = new Node;
             t->data = val;
             t->prev = p;
             t->next = p->next;
             if(p->next)t->next->prev = t;
             p->next = t;
        }
    }
}

void Delete(struct Node *p, int index){
    int x = -1, i;

    if(index > Length(p) || index < 1){
        return;
    }
    else{
        if(index == 1){
            first = first->next;
            if(first) first->prev = NULL;
            delete p;
        }
        else{
            for(i = 0; i < index-1; i++){
                p = p->next;
            }
            p->prev->next=p->next;
            if(p->next){
                p->next->prev = p->prev;
            }
            delete p;
        }
    }
}

int main(){
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    // insertInto(first, 1, 45);
    cout << "Length: " << Length(first) << endl;
    Delete(first, 5);
    Display(first);

    return 0;
}