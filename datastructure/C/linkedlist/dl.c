#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
}*first = NULL;

struct poly{
    int coeff;
    int exp;
    struct poly *forward;
}*p_poly = NULL;

struct sparse{
    int col;
    int value;
    struct sparse *next;
};

void create_sparse(int row, int n, struct sparse *A[])
{
    int i;
    int c_row,c_col,val;
    struct sparse *temp,*p;
    for(i = 0; i < row; i++)
        A[i] = NULL;
    for(i = 0; i < n; i++){
        temp = (struct sparse *) malloc(sizeof(struct sparse));
        scanf("%d%d%d",&c_row,&temp->col,&temp->value);
        if(A[c_row] == NULL){
            A[c_row] = p = temp;
            p->next = NULL;
        }
        else{
            p->next = temp;
            p = temp;
            p->next = NULL;
        }
    }
}
void DisplaySparse(int row, int col,struct sparse *A[])
{
    int i,j;
    struct sparse *p;
    for(i = 0; i < row; i++){
        p = A[i];
        for(j = 0; j < col; j++){
            if(j == p->col){
                printf("%d ",i);
                p= p->next;
            }
            else
                printf("0 ");
        }
        printf("\n");
    }
}
void create(int A[], int n)
{
    struct Node *temp,*last;
    int i;
    first = (struct Node*) malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = first->previous = NULL;
    last = first;

    for(i = 1; i < n; i++){
        temp = (struct Node*) malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = last->next;
        temp->previous = last;
        last->next = temp;
        last = temp;
    }
}
int length(struct Node *p)
{
    int len = 0;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}
void Display(struct Node *p)
{
    while(p){
        printf("%d ",p->data);
        p = p->next;
    }
    printf("\n");
}
void Insert(struct Node *p,int index, int x)
{
    int i;
    struct Node *t;
    if (index < 0 || index > length(first))
        return;
    if(index == 0){
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->previous = first->previous;
        first->previous = t;
        t->next = first;
        first = t;
    }
    else{
        for(i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct Node*) malloc(sizeof(struct Node));
        t->data = x;
        t->previous = p;
        t->next = p->next;
        if(p->next)
            p->next->previous = t;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    int x = -1, i;
    if(index < 1 || index > length(first))
        return -1;
    if(index == 1){
        first = first->next;
        if(first)first->previous = NULL;
        x = p->data;
        free(p);
    }
    else{
        for(i = 0; i < index - 1; i++)
            p = p->next;
        p->previous->next = p->next;
        if(p->next)p->next->previous = p->previous;
        x = p->data;
        free(p);
    }
    return x;
}
void Reverse(struct Node *p)
{
    struct Node *temp;
    while(p != NULL){
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if(p!= NULL && p->next == NULL)
            first = p;
    }
}
void create_poly()
{
    int num,i;
    struct poly *t,*last = NULL;
    scanf("%d",&num);
    for(i = 0; i < num; i++){
        t = (struct poly*) malloc(sizeof(struct poly));
        scanf("%d%d",&t->coeff,&t->exp);
        t->forward = NULL;
        if(p_poly==NULL)
            p_poly = last = t;
        else{
            last->forward = t;
            last = t;
        }
    }
}
void DisplayPoly(struct poly *p)
{
    while(p->forward != NULL){
        printf("%dx^%d + ",p->coeff,p->exp);
        p  = p->forward;
    }
    printf("%dx^%d\n",p->coeff,p->exp);
}
long Eval(struct poly *p, int x)
{
    long val = 0;
    while(p){
        val += p->coeff * pow(x,p->exp);
        p = p->forward;
    }
    return val;
}
int main()
{
    create_poly();
    DisplayPoly(p_poly);
    printf("%ld\n",Eval(p_poly,1));
    return 0;
}