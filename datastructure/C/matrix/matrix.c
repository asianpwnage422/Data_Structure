#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *A;
    int n;
}matrix;

typedef struct
{
    int i;
    int j;
    int x;
}element;

typedef struct
{
    int m;
    int n;
    int num;
    element* array;
}sparse;

void create_sparse(sparse *S)
{
    int i;
    printf("Enter m,n,num : \n");
    scanf("%d%d%d",&S->m,&S->n,&S->num);
    S->array = (element*)malloc(S->num * sizeof(element));
    printf("Enter elements :\n");
    for(i = 0; i < S->num; i++)
        scanf("%d%d%d",&S->array[i].i,&S->array[i].j,&S->array[i].x);
}
void Display_sparse(sparse S)
{
    int i, j, k=0;

    for(i=0;i<S.n;i++){
        for(j=0;j<S.m;j++){
            if(i==S.array[k].i && j==S.array[k].j)
                printf("%d ",S.array[k++].x);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
sparse* add_sparse(sparse *s1, sparse *s2)
{
    int i=0, j=0, k=0;
    sparse* sum;
    if(s1->m != s2->m && s1->n != s2->n)
        return NULL;
    sum = (sparse*) malloc(sizeof(sparse));
    sum->array = (element*) malloc((s1->num + s2->num)*sizeof(element));
    //s1 array element row is smaller, else if s2 array element row is smaller
    //else they are in same row -> compare col -> if col is same , add
    while(i < s1->num && j < s2->num){
        if(s1->array[i].i < s2->array[j].i)
            sum->array[k++] = s1->array[i++];
        else if(s1->array[i].i > s2->array[j].i)
            sum->array[k++] = s2->array[j++];
        else{
            if(s1->array[i].j < s2->array[j].j)
                sum->array[k++] = s1->array[i++];
            else if(s1->array[i].j > s2->array[j].j)
                sum->array[k++] = s2->array[j++];
            else{
                sum->array[k] = s1->array[i];
                sum->array[k++].x = s1->array[i++].x + s2->array[j++].x;
            }
        }
    }
    for(;i<s1->num;i++)
        sum->array[k++] = s1->array[i];
    for(;j<s2->num;j++)
        sum->array[k++] = s2->array[j];
    sum->m = s1->m;
    sum->n = s2->n;
    return sum;
}
int main()
{
    sparse s1,s2;
    sparse *s3;
    create_sparse(&s1);
    create_sparse(&s2);
    s3 = add_sparse(&s1,&s2);
    Display_sparse(s1);
    printf("\n");
    Display_sparse(s2);
    printf("\n");
    Display_sparse(*s3);
    return 0;
}
