#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL,*second = NULL, *third = NULL, *Head = NULL;

void create_ll(int A[], int n)
{
    int i;
    struct Node *p,*last;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i = 1; i < n; i++){
        p = (struct Node*) malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void create2(int A[], int n)
{
    int i;
    struct Node *p,*last;
    second = (struct Node*) malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

    for(i = 1; i < n; i++){
        p = (struct Node*) malloc(sizeof(struct Node));
        p->data = A[i];
        p->next = NULL;
        last->next = p;
        last = p;
    }
}
void create_circular(int A[], int n)
{
    int i;
    struct Node *temp,*last;
    //first Node
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(i = 1; i < n; i++){
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = A[i];
        last->next = temp;
        last = temp;
        temp->next = Head;
    }
}
void cirDisplay(struct Node *head)
{
    struct Node *p = head;
    do{
        printf("%d ", p->data);
        p = p->next;
    }while(p != head);    
}
void Display(struct Node* first)
{
    struct Node *p;
    p = first;
    while(p != NULL){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
void RDisplay(struct Node* p)
{
    if(p != NULL){
        printf("%d ",p->data);
        RDisplay(p->next);
    }
}
int count(struct Node *p)
{
    int count = 0;
    while(p != NULL){
        count++;
        p= p->next;
    }
    return count;
}
int Rcount(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
        return Rcount(p->next) + 1;
        
}
int sum(struct Node *p)
{
    int sum = 0;
    while(p != NULL){
        sum+=p->data;
        p = p->next;
    }
    return sum;
}
int Rsum(struct Node *p)
{
    if(p == NULL)
        return 0;
    else
    {
        return Rsum(p->next) + p->data;
    }
    
}
int max(struct Node *p)
{
    int x = INT32_MIN;
    while(p != NULL){
        if(p->data > x)
            x = p->data;
        p = p ->next;
    }
    return x;
}
int Rmax(struct Node *p)
{
    int max;
    if(p == NULL)
        return INT32_MIN;
    max = Rmax(p->next);
    if(p->data > max)
        max = p->data;
    return max;
}
struct Node *Lsearch(int key, struct Node *p)
{
    struct Node *q = NULL;
    while(p != NULL){
        if(key == p->data){
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
struct Node *RLsearch(int key, struct Node *p)
{
    if(p == NULL)
        return NULL;
    if(p->data == key)
        return p;
    return RLsearch(key,p->next);
}
void Insert(struct Node *p, int index, int x)
{
    int i;
    struct Node *temp;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = x;
    if(index < 0 || index > count(p))
        return;
    if(index == 0){
        temp->next = first;
        first = temp;
    }
    else{
        for(i = 0; i < index; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
}
void SortedInsert(struct Node *p, int x)
{
    struct Node *temp,*q = NULL;
    temp = (struct Node*) malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    if(first == NULL)
        first = temp;
    else{
        while(p != NULL && p->data < x){
            q = p;
            p = p->next;
        }
        if(first == p){
            temp->next = first;
            first = temp;
        }
        else{
            q->next = temp;
            temp->next = p;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1;
    int i;
    if(index < 1 || index > count(first))
        return -1;
    else{
        for(i=0; i<index-1; i++){
            q = p;
            p = p->next;
        }
        if(p == first){
            first = first->next;
            x = p->data;
            free(p);
        }
        else{
            q->next = p->next;
            x = p->data;
            free(p);
        }
        return x;
    }
}
int isSorted(struct Node *p)
{
    int x = -INT32_MIN;
    while(p != NULL){
        if(p->data < x)
            return 0;
        else
        {
            x = p->data;
            p = p->next;
        }
    }
    return 1;
}
void RemoveDup(struct Node *p)
{
    struct Node *q = p->next;
    while(q != NULL){
        if(q->data != p->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            free(q);
            q = q->next;
        }
    }
}
void ReverseArray(struct Node *p)
{
    int i = 0;
    struct Node *q = p;
    int *A;
    A = (int*) malloc(count(p) * sizeof(int));
    while(q != NULL){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q != NULL){
        q->data = A[i--];
        q = q->next;
    }
}
void ReverseLink(struct Node *p)
{
    struct Node *r = NULL,*q = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
     }
     first = q;
}
void Reverse3(struct Node *q, struct Node *p)
{
    if(p != NULL){
        Reverse3(p, p->next);
        p->next = q;
    }
    else
        first = q;
}
void concate(struct Node *p, struct Node *q)
{
    third = p;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
}
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    //first Node
    if(p->data < q->data){
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
        last->next = q;
        last = q;
        q = q->next;
        last->next = NULL;
        }
    }
    if(p != NULL)
        last->next = p;
    else if(q != NULL)
        last->next = q;
}
int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do{
        p = p->next;
        q = q->next;
        q = q?q->next:q;
    }
    while(p && q && p != q);
    return p == q?1:0;
}
void cirRDisplay(struct Node *p)
{
    static int flag = 0;
    if(flag == 0 || p != Head){
        flag = 1;
        printf("%d ",p->data);
        cirRDisplay(p->next);
    }
}
int length(struct Node *p)
{
    int len = 0;
    do{
        p = p->next;
        len++;
    }while(p!=Head);
    return len;
}
void cirInsert(int pos, int x)
{
    int i;
    struct Node *p = Head;
    if(pos < 0 || pos > length(Head))
        return;
    struct Node *t = (struct Node*) malloc(sizeof(struct Node));
    t->data = x;
    if(pos == 0){
        if(Head == NULL){
            Head = t;
            Head->next = Head;
        }
        else{
            while(p->next != Head)
                p = p->next;
            p->next = t;
            t->next = Head;
            Head = t;
        }
    }
    else{
        for(i = 0; i < pos-1;i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
int cirDelete(int index, struct Node *p)
{
    struct Node *q;
    int i,x;
    
    if(index < 1 || index > length(Head)) return 0;
    //delete head node
    if(index == 1){
        while(p->next != Head) p = p->next;
        if(p == Head){
            x = Head->data;
            free(Head);
            Head = NULL;
        }
        else{
            p->next = Head->next;
            x = Head->data;
            free(Head);
            Head = p->next;
        }
    }
    else{
        for(i = 0; i < index-1; i++) p = p->next;
        q = p->next;
        p->next = q->next;
        x = q->data;
        free(q);
    }
    return x;
}
int main()
{
    struct Node *t1,*t2;
    int A[] = {1,2,3,4,5};
    create_circular(A,5);
    cirInsert(4,44);
    cirDelete(5,Head);
    cirRDisplay(Head);
    return 0;
}
